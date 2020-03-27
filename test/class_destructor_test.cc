#include "gtest/gtest.h"

class Garbdge {
    bool &destroyed;
    public:
    Garbdge(bool &destroyed): destroyed{ destroyed} {}
    ~Garbdge() {
        destroyed = true;
    }
};


TEST(Destructor, should_be_called_if_destroy_dynamic_aollocated_object_explicitly) {
    bool destroyed { false };
    Garbdge *garbdge{ new Garbdge{ destroyed } };

    ASSERT_FALSE(destroyed) << "destroyed";

    delete garbdge;
    ASSERT_TRUE(destroyed) << "active";
}


TEST(Destructor, should_avoid_to_be_called_directly) {
    bool destroyed { false };
    Garbdge *garbdge{ new Garbdge{ destroyed } };

    garbdge->~Garbdge(); //should be avoid

    ASSERT_TRUE(destroyed) << "active";
}


TEST(Destructor, should_be_called_when_static_allocated_object_out_of_the_scope) {
    bool destroyed { false };
    auto call {
        [&destroyed]() {
            //      v-- assigned to the local variable `unused`
            Garbdge unused{ destroyed }; 
            ASSERT_FALSE(destroyed) << "doesn't out of the scope";
        }
    };

    ASSERT_FALSE(destroyed) << "destroyed";
    call();
    ASSERT_TRUE(destroyed) << "active";
}


TEST(Destructor, should_be_called_immeidately_for_object_has_no_referenced_variables) {
    bool destroyed { false };
    auto call {
        [&destroyed]() {
            //     v--no assignment
            Garbdge{ destroyed }; 
            ASSERT_TRUE(destroyed) << "should be destroyed if there is no any reference";
        }
    };

    ASSERT_FALSE(destroyed) << "destroyed";
    call();
    ASSERT_TRUE(destroyed) << "active";
}


