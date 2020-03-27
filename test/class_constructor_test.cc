#include "gtest/gtest.h"


TEST(Constructor, create_class_instance_with_implict_constructor) {
    class Counter {
        int count{ 0 };
        public:
        void incr() {
            ++count;
        }

        int value() {
            return count;
        }
    };

    Counter counter;
    ASSERT_EQ(0, counter.value());

    counter.incr();
    ASSERT_EQ(1, counter.value());

    counter.incr();
    ASSERT_EQ(2, counter.value());
}


TEST(Constructor, create_class_instance_with_default_constructor) {
    class Counter {
        int count{ 0 };
        public:
        //generate default constructor
        Counter() = default;

        void incr() {
            ++count;
        }

        int value() {
            return count;
        }
    };

    Counter counter;

    counter.incr();
    ASSERT_EQ(1, counter.value());
}


TEST(Constructor, create_class_instance_with_custom_constructor) {
    class Item {
        double price;
        int qty;
        public:
            Item(double price, int qty) {
                this->price = price;
                this->qty = qty;
            }

            double totalPrice() {
                return price * qty;
            }
    };

    Item item{ 1.5, 3 };

    ASSERT_EQ(4.5, item.totalPrice());
}


TEST(Constructor, class_type_member_fields_will_be_initialized_even_if_they_do_not_initialized_explicitly) {
    static std::string log {""};

    class Profile {
        public:
            Profile() {
                log += "profile ";
            }
    };
    class Project {
        Profile profile;
        public:
            Project() {
                log += "project ";
            }
    };

    Project project;

    ASSERT_EQ("profile project ", log);
}


TEST(Constructor, initialize_member_fields_by_member_initializer_list) {
    class Item {
        public:
            const int qty;
            Item(int qty): qty{ qty }{/*initialize fields with member initializer list*/}
    };

    Item item{ 3 };

    ASSERT_EQ(3, item.qty);
}

#include <stdexcept>
static int fail(std::string message) {
    throw std::logic_error(message);
}

TEST(Constructor, non_static_member_initialization_not_to_be_called_if_member_initializer_list_has_initialized_it) {
    class Item {
        public:
            int qty{ fail("should not called") };
            Item(int qty): qty{ qty }{}
    };

    Item item{ 3 };

    ASSERT_EQ(3, item.qty);
}


TEST(Constructor, non_static_member_initialization_will_be_called_if_initializing_member_through_constructor) {
    class Item {
        public:
            int qty{ fail("ok") };
            Item(int qty) {
                this->qty = qty;
            }
    };

    try{
        Item(3);
        throw std::runtime_error("should be failed");
    } catch(std::logic_error &expected) {
        ASSERT_EQ("ok", std::string_view(expected.what()));
    }
}


TEST(Constructor, delegating_constructor_to_another_constructor_to_avoid_overlapping_functionality) {
    class Item {
        double price;
        int qty;

        public:
            Item(double price): /*delegate to another constructor*/ Item(price, 1) {
            }

            Item(double price, int qty): price{price}, qty{qty} {
            }

            double totalPrice() {
                return price * qty;
            }
    };

    ASSERT_EQ(1.5, Item(1.5).totalPrice());
    ASSERT_EQ(4.5, Item(1.5, 3).totalPrice());
}


TEST(Constructor, prevent_implicit_conversion_by_make_constructor_explicit) {
    class String {
        std::string s;
        public:
            explicit String(int value): s{ std::to_string(value) }  {
            }

            String(const char *str): s{ static_cast<std::string>(str) } {
            }

            const std::string& toString() {
                return s;
            }
    };
    
    //String s = 'x'; //compile time error: can't be convert implicitly
    String direct('x'); //convert explicit
    ASSERT_EQ("120", direct.toString()) << "String(int) should be called explicit";
}


TEST(Constructor, prevent_all_conversions_by_mark_constructor_as_deleted) {
    class String {
        std::string s;
        public:
            String(char) = delete;
            String(const char *str): s{ static_cast<std::string>(str) } {
            }

            const std::string& toString() {
                return s;
            }
    };
    
    //String s = 'x'; //compile time error: can't be convert implicitly
    //String direct('x'); //compile time error: can't be convert explicit
    ASSERT_EQ("abc", String("abc").toString());
}


