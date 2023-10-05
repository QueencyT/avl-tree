#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/avl/avl.h"
#include "../../includes/avl/avl_functions.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_rotate_left(bool debug){
  if(debug){
    cout<<"testing rotate_left: simple case\n";  
    tree_node<int>* mRoot = new tree_node<int>(3); 
    tree_insert(mRoot, 2); 
    tree_insert(mRoot, 1); 

    tree_print(mRoot, 0, cout);  

    cout<<"after rotation: \n"; 
    rotate_left(mRoot); 
    tree_print(mRoot, 0, cout); 
  }

  if(debug){
    cout<<"testing rotate left: complicated case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(3); 
    tree_insert(mRoot, 2); 
    tree_insert(mRoot, 1);
    tree_insert(mRoot, 1); 
    tree_insert(mRoot, 0); 

    cout<<"before rotation: \n"; 
    tree_print(mRoot, 0, cout);

    cout<<"after rotation: \n"; 
    rotate_left(mRoot); 
    tree_print(mRoot, 0, cout); 
  }
}

bool test_rotate_right(bool debug){
  if(debug){
    cout<<"testing rotate right: simple case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(3); 
    tree_insert(mRoot, 4); 
    tree_insert(mRoot, 5); 

    cout<<"before right rotattion: \n"; 
    tree_print(mRoot, 0, cout); 

    cout<<"after right rotation: \n"; 
    //rotate_right(mRoot); 
    tree_print(mRoot, 0, cout);
  }

   if(debug){
    cout<<"testing rotate right: complex case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(3); 
    tree_insert(mRoot, 4); 
    tree_insert(mRoot, 7); 
    tree_insert(mRoot, 6);

    cout<<"before right rotation: \n"; 
    tree_print(mRoot, 0, cout); 

    cout<<"after right rotation: \n"; 
    rotate_right(mRoot); 
    tree_print(mRoot, 0, cout);
  }
}

//whe right heavy but leaning left
bool test_rotate_mirror_right(bool debug){
  if(debug){
    cout<<"testing rotate_mirror_right simple case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(3); 
    tree_insert(mRoot, 5);
    tree_insert(mRoot, 4); 

   
    cout<<"before mirror right rotation: \n"; 
    tree_print(mRoot,0, cout); 
    cout<<endl; 
    tree_print_debug(mRoot, 0, cout);  

    cout<<"After mirror right rotation: \n"; 
    //rotate_left(mRoot->_right);
   // rotate_right(mRoot);
    //rotate_mirror_right(mRoot); 
    //tree_print(mRoot, 0, cout); 
  } 

  if(false){
    cout<<"testing rotate_mirror_right complex case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(7); 
    tree_insert(mRoot, 6); 
    tree_insert(mRoot, 12); 
    tree_insert(mRoot, 13); 
    tree_insert(mRoot, 9); 
    tree_insert(mRoot, 10); 
    tree_insert(mRoot, 8); 

    cout<<"before mirror right rotation: \n";
    tree_print(mRoot, 0, cout); 

    cout<<"after mirror right rotation: \n"; 
    //rotate_left(mRoot->_right);
    //rotate_right(mRoot);
    rotate_mirror_right(mRoot); 
    tree_print(mRoot, 0, cout); 
  }
}

bool test_rotate_mirror_left(bool debug){
  if(debug){
    cout<<"testing rotate mirror left simple case\n"; 
    tree_node<int>* mRoot = new tree_node<int>(5); 
    tree_insert(mRoot, 3); 
    tree_insert(mRoot, 4); 

    cout<<"before mirror left rotation: \n"; 
    tree_print(mRoot, 0, cout); 

    cout<<"after mirror left rotation: \n"; 
    //rotate_mirror_left(mRoot); 
    //tree_print(mRoot, 0, cout); 
  }
}

bool test_quick(bool debug){
  //0 0 1 2 3 4 4 5 6 7 8 8 9 10 11 12 12 13 14 15 16 16 17 18 19 20 20 21 22 23 24 24 25 26 27 28 28 29 30 31 

  if(debug){
    int a[] = {62, 18, 72, 10, 34, 38, 28, 80, 56, 52, 62, 32, 92, 62, 90, 78, 56, 30, 60, 26, 72, 38, 94, 60, 16, 66, 90, 28, 74, 70, 84, 26, 44, 36, 34, 28, 74, 80, 90, 72, 56, 80, 24, 48, 84, 62, 22, 94, 18, 66};
    tree_node<int>* mTree = NULL; 

    for(int i = 0; i < 50; i++){
      tree_insert(mTree, a[i]); 
    } 

    cout<<"in order: "<<in_order_string(mTree)<<endl;
    cout<<"post order: "<<post_order_string(mTree)<<endl; 
    cout<<"pre order: "<<pre_order_string(mTree)<<endl; 
   // AVL<int> avl(a, 50); 
    //AVL<int> avl2(avl); 

    
  }
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_AVL, testRotateLeft){
  EXPECT_EQ(1, test_rotate_left(false)); 
}

TEST(TEST_AVL, testRotateRight){
  EXPECT_EQ(1, test_rotate_right(false)); 
}

TEST(TEST_AVL, testRotateMirrorRight){
  EXPECT_EQ(1, test_rotate_mirror_right(false)); 
}

TEST(TEST_AVL, testRotateMirrorLeft){
  EXPECT_EQ(1, test_rotate_mirror_left(false));
}

TEST(TEST_AVL, testQuick){
  EXPECT_EQ(1, test_quick(true));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

