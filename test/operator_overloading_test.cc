#include "gtest/gtest.h"

class Value {
    public:
        int value;

        Value operator -() const;
        Value operator +(const Value &addend);
        friend Value operator +(const Value &augend, const int addend);
        friend Value operator +(const int augend, const Value &addend) {
            return addend + augend;
        }

        Value& operator ++();
        Value operator ++(int);

        int& operator[](int index);

        operator int() const;

};

//override operator for debug purpose
#include <iostream>
std::ostream& operator <<(std::ostream &out, const Value &value) {
    out << "Value(" << value.value << ")";
    return out;
}

Value operator +(const Value &augend, const int addend) {
    return Value { augend.value + addend };
}
TEST(Opeartor, friend_operator_overloading_with_different_operand_types) {
    Value value { 1 };

    Value sum = 2 + value;
    ASSERT_EQ(Value{ 3 }, sum);

    sum = value + 4;
    ASSERT_EQ(Value{ 5 }, sum);
}


bool operator==(const Value &left, const Value &right) {
    return left.value == right.value;
}
bool operator!=(const Value &left, const Value &right) {
    return !(left == right);
}
TEST(Opeartor, normal_function_operator_overloading_without_declare_the_function_in_class_declaration) {
    ASSERT_EQ(Value{ 1 }, Value{ 1 });
    ASSERT_NE(Value{ 1 }, Value{ 2 });
}


Value Value::operator +(const Value &addend) {
    return Value{ value + addend.value };
}
TEST(Opeartor, operator_member_function_overloading) {
    Value augend{ 1 };
    Value addend{ 2 };

    Value sum { augend + addend };

    ASSERT_EQ(Value{ 3 }, sum);
}


Value Value::operator -() const {
    return Value{ -value };
}
TEST(Opeartor, unary_operator_overloading_using_const_member_function) {
    Value value{ 1 };

    Value negated { -value };

    ASSERT_EQ(Value{ -1 }, negated);
}


Value& Value::operator ++() {
    ++value;
    return *this;
}
TEST(Opeartor, overload_prefix_increment_operator) {
    Value value{ 1 };

    Value &result{ ++value };

    ASSERT_EQ(&value, &result);
    ASSERT_EQ(Value{ 2 }, result);
    ASSERT_EQ(Value{ 2 }, value);
}


Value Value::operator ++(int value/*dummy parameter to distinguish prefix increment*/) {
    Value snap{ *this };
    return (++(*this), snap);
}
TEST(Opeartor, overload_postfix_increment_operator) {
    Value value{ 1 };

    Value result{ value++ };

    ASSERT_NE(&value, &result);
    ASSERT_EQ(Value{ 1 }, result);
    ASSERT_EQ(Value{ 2 }, value);
}


int& Value::operator[](int index) {
    if(index) {
        throw std::out_of_range("size: 1, but index: " +index);
    }
    return value;
}
TEST(Opeartor, subscript_operator_must_be_return_a_reference_since_it_can_be_used_as_lvalue_for_assginment) {
    Value value{ 1 };
    ASSERT_EQ(1, value[0]);

    value[0] = 3;
    ASSERT_EQ(3, value[0]);

    try{
        value[1];
        throw std::logic_error("should be failed");
    }catch(std::out_of_range& expected) {
    }
}


TEST(Opeartor, access_a_pointer_subscript_must_be_deference_first) {
    Value value{ 1 };

    Value *ptr { &value };

    ASSERT_EQ(1, (*ptr)[0]);
}


Value::operator int() const {
    return value;
}
TEST(Opeartor, convert_object_by_overloading_typecast_operator) {
    Value value{ 1 };

    int cast { value };

    ASSERT_EQ(1, cast);
}

