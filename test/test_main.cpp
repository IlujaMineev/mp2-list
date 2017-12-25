#include <gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//#include "list.h"
//
//void main()
//{
//	List A;
//	A.InserToTail(3);
//	A.InserToTail(2);
//	A.InserToTail(1);
//	A.PrintList();
//	A.Delete(5);
//	A.PrintList();
//}
