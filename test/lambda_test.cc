#include "gtest/gtest.h"


TEST(Lambda, standard_function_literal_form) {
    int (*run)() {
        [/*captures*/](/*parameters*/) -> /*return type*/int {
            return 3;
        }
    };

    ASSERT_EQ(3, (*run)()) << "dereference function pointer failed";
    ASSERT_EQ(3, run()) << "implicit function dereference";
}


TEST(Lambda, return_type_is_optional) {
    int (*run)() {
        []() {
            return 1;
        }
    };

    ASSERT_EQ(1, run());
}


TEST(Lambda, lambda_parameters) {
    int (*sum)(int, int) {
        [](int a, int b) {
            return a + b;
        }
    };

    ASSERT_EQ(3, sum(1, 2));
}


TEST(Lambda, use_auto_to_define_lambda) {
    auto sum {
        [](int a, int b) {
            return a + b;
        }
    };

    ASSERT_EQ(3, sum(1, 2));
}


TEST(Lambda, use_std_function_to_define_lambda) {
    std::function<int(int, int)> sum {
        [](int a, int b) {
            return a + b;
        }
    };

    ASSERT_EQ(3, sum(1, 2));
}


TEST(Lambda, use_auto_parameters_for_generic_parameters) {
    auto sum {
        [](auto a, auto b) {
            return a + b;
        }
    };

    ASSERT_EQ(3, sum(1, 2));
    ASSERT_EQ(3.2, sum(1.1, 2.1));
}


TEST(Lambda, static_variable_not_shared_for_generic_lambda_of_different_parameter_types_since_each_version_lambda_was_generated_by_compiler) {
    auto call {
        [](auto a) {
            static int calls {0};
            return ++calls;
        }
    };

    ASSERT_EQ(1, call(0));
    ASSERT_EQ(2, call(1));
    ASSERT_EQ(1, call("other")) << "static variable should not be shared for generic parameter types";
}


TEST(Lambda, access_compile_time_variable_without_any_captures) {
    const int value{ 1 };

    auto run {
        [](){
            return value;
        }
    };


    ASSERT_EQ(1, run());
}


static int value{ 2 };
TEST(Lambda, access_global_variable_without_any_captures) {

    auto run {
        [](){
            return value;
        }
    };


    ASSERT_EQ(2, run());
}



TEST(Lambda, access_static_variable_without_any_captures) {
    static int value{ 3 };

    auto run {
        [](){
            return ++value;
        }
    };


    ASSERT_EQ(4, ++value);
    ASSERT_EQ(5, run()) << "static variable will use as reference implicitly";
    ASSERT_EQ(5, value);
}



TEST(Lambda, variables_captures) {
    int value{ 1 };

    auto run {
        [value/*variable captures*/](){
            return value;
        }
    };


    ASSERT_EQ(2, ++value);
    ASSERT_EQ(1, run()) << "value is copied in lambda";
}



TEST(Lambda, mutable_variables_captures_is_preserved_like_as_static_variable) {
    int value{ 1 };

    auto run {
        [value/*variable captures*/]() mutable {
            return ++value;
        }
    };


    ASSERT_EQ(5, value = 5);
    ASSERT_EQ(2, run()) << "value is copied";
    ASSERT_EQ(3, run()) << "value shold be used as static-variable";
    ASSERT_EQ(5, value) << "captured variable can't be changed since it is a copyed-value";
}



TEST(Lambda, reference_captures) {
    int value{ 1 };

    auto run {
        [&value/*reference captures*/](){
            return ++value;
        }
    };


    ASSERT_EQ(2, run());
    ASSERT_EQ(2, value);
}


TEST(Lambda, multiple_captures_separated_by_comma) {
    int value{ 1 };
    int other{ 3 };

    auto run {
        [&value, other](){
            return ++value + other;
        }
    };


    ASSERT_EQ(5, run());
    ASSERT_EQ(2, value);
}



TEST(Lambda, clone_all_variables_captures) {
    int value{ 1 };
    int other{ 3 };

    auto run {
        [=](){
            return value + other;
        }
    };


    ASSERT_EQ(4, run());
}


TEST(Lambda, captures_all_local_variable_as_references) {
    int value{ 1 };
    int other{ 3 };

    auto run {
        [&](){
            return ++value + ++other;
        }
    };


    ASSERT_EQ(6, run());
    ASSERT_EQ(2, value);
    ASSERT_EQ(4, other);
}


TEST(Lambda, define_new_variables_in_lambda_captures) {
    int value{ 1 };
    int other{ 3 };

    auto run {
        [sum{ value + other }](){
            return sum * 2;
        }
    };


    ASSERT_EQ(8, run());
    ASSERT_EQ(1, value);
    ASSERT_EQ(3, other);
}


TEST(Lambda, copy_lambda_will_also_copy_all_mutable_captures) {
    int value{ 1 };

    auto run {
        [value]() mutable {
            return ++value;
        }
    };

    ASSERT_EQ(2, run());

    auto run2 { run };

    ASSERT_EQ(3, run());
    ASSERT_EQ(4, run());
    ASSERT_EQ(3, run2()) << "mutable captures are copied not shared between any lambdas";
}


TEST(Lambda, assign_lambda_with_pointer_use_std_ref_to_avoid_lambda_copy) {
    int value{ 1 };

    auto run {
        [value]() mutable {
            return ++value;
        }
    };

    ASSERT_EQ(2, run());

    std::function<int()> run2{ std::ref(run) };

    ASSERT_EQ(3, run());
    ASSERT_EQ(4, run());
    ASSERT_EQ(5, run2()) << "lambda should not copied";
}


