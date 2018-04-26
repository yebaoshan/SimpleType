/**
 * @file stackTest.c
 * @brief Test case of google test for sequential stack and linked stack
 * @author Baoshan Ye <yebaoshan.scutech@gmail.com>
 */

#include "stack.h"
#include "rw_mutex.h"
#include "faked_mutex.h"
#include "sequential_stack.cpp"
#include "linked_stack.cpp"
#include <gtest/gtest.h>

Stack<int, Sequential_Stack<int, 100>, Faked_Mutex> s1;  ///< The global variable of BridgeStack class for unlocked sequential stack, initialized to empty
Stack<char, Sequential_Stack<char, 124>, RW_Mutex> s2; ///< The global variable of BridgeStack class for locked sequential stack, initialized to full
Stack<int, Linked_Stack<int>, Faked_Mutex > l1;  ///< The global variable of BridgeStack class for unlocked Linked stack, initialized to empty
Stack<char, Linked_Stack<char>, RW_Mutex> l2; ///< The global variable of BridgeStack class for locked Linked stack, initialized to no empty

/**
 * @brief The TestSuite class of sequential stack 
 */
class SequentialStackTest1: public testing::Test
{
public:
	/**
	 * @brief executing before the first test case
	 */
	static void SetUpTestCase()
	{                                    
		printf("The test beginning of sequential stack\n");
	}

	/**
	 * @brief executing after the last test case
	 */
	static void TearDownTestCase() 
	{                              
		printf("The test end of sequential stack\n");	
	}
};

/**
 * @brief The TestSuite class of linked stack
 */
class LinkedStackTest1: public testing::Test
{
public:
	/**
	 * @brief executing before the first test case 
	 */
	static void SetUpTestCase()  
	{                                   
		printf("The test beginning of linked stack\n");
	}

	/**
	 * @brief executing after the last test case 
	 */
	static void TearDownTestCase() 
	{
		printf("The test end of linked stack\n");	
	}
};

/**
 * @brief The test for pushing into stack function of sequential stack
 */
TEST_F(SequentialStackTest1, Push)
{
	printf("The test for push()\n");
	for (int i = 0; i < 124; i++)
		EXPECT_TRUE(s2.push(i));
   EXPECT_FALSE(s2.push('1'));	
}

/**
 * @brief The test for length function of sequential stack
 */
TEST_F(SequentialStackTest1, Length)
{
	printf("The test for leng()\n");
	EXPECT_EQ(s1.length(), 0);
	EXPECT_EQ(s2.length(), 124);
}

/**
 * @brief The test for getting the top element function of sequential stack
 */
TEST_F(SequentialStackTest1, Get_Top)
{
	printf("The test for get_top()\n");
	EXPECT_NO_THROW(s1.get_top());
	EXPECT_EQ(s2.get_top(), '{');
}

/**
 * @brief The test for judging full function of sequential stack
 */
TEST_F(SequentialStackTest1, Full)
{
	printf("The test for full()\n");
	EXPECT_FALSE(s1.full());          
	EXPECT_TRUE(s2.full());
}

/**
 * @brief The test for judging empty function of sequential stack
 */
TEST_F(SequentialStackTest1, Empty)
{
	printf("The test for empty()\n");	
	EXPECT_TRUE(s1.empty());
	EXPECT_FALSE(s2.empty());
}

/**
 * @brief The test for poping up stack function of sequential stack
 */
TEST_F(SequentialStackTest1, Pop)
{
	printf("The test for pop()\n");
	EXPECT_NO_THROW(s1.pop());       
	EXPECT_EQ(s2.pop(), '{');     
	EXPECT_EQ(s2.get_top(), 'z');
}

/**
 * @brief The test for clearing all data function of sequential stack
 */
TEST_F(SequentialStackTest1, Clear)
{
	printf("The test for clear()\n");
	s2.clear();
	EXPECT_TRUE(s2.empty());
}

/**
 * @brief The test for pushing into stack function of linked stack
 */
TEST_F(LinkedStackTest1, Push)
{
	printf("The test for push()\n");
	for (int i = 0; i < 124; i++)
		EXPECT_TRUE(l2.push(i));
}

/**
 * @brief The test for length function of linked stack
 */
TEST_F(LinkedStackTest1, Length)
{
	printf("The test for leng()\n");
	EXPECT_EQ(l1.length(),0);   
	EXPECT_EQ(l2.length(),124);
}

/**
 * @brief The test for getting the top element function of linked stack
 */
TEST_F(LinkedStackTest1, Get_Top)
{
	printf("The test for get_top()\n");
	EXPECT_NO_THROW(l1.get_top());
	EXPECT_EQ(l2.get_top(), '{');
}

/**
 * @brief The test for judging full function of linked stack
 */
TEST_F(LinkedStackTest1, Full)
{
	printf("The test for full()\n");
	EXPECT_FALSE(l1.full());          
	EXPECT_FALSE(l2.full());
}

/**
 * @brief The test for judging empty function of linked stack
 */
TEST_F(LinkedStackTest1, Empty)
{
	printf("The test for empty()\n");	
	EXPECT_TRUE(l1.empty());
	EXPECT_FALSE(l2.empty());
}

/**
 * @brief The test for poping up stack function of linked stack
 */
TEST_F(LinkedStackTest1, Pop)
{
	printf("The test for pop()\n");
	EXPECT_NO_THROW(l1.pop());
	EXPECT_EQ(l2.pop(), '{');
	EXPECT_EQ(l2.get_top(), 'z');
}

/**
 * @brief The test for clearing all data function of linked stack
 */
TEST_F(LinkedStackTest1, Clear)
{
	printf("The test for clear()\n");
	l2.clear();
	EXPECT_TRUE(l2.empty());   
}

/**
 * @brief The test for main function entry of  stack
 */
int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
