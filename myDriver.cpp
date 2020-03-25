////
//// Created by Kemba Konteh on 1/30/20.
////
//
//#include "myDriver.h"
//
//#include "BinTree.h"
//#include <string>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//const int ARRAYSIZE=100;
//void initArray(NodeData* ndArray[]);
//int main() {
//
//    NodeData* ndArray[ARRAYSIZE];
//    initArray(ndArray);
//
//    BinTree b;
//    BinTree b2;
//    BinTree b4;
//    string s="Hello";
//    string s1="World";
//    string s2="Kemba";
//    string s3="Gambia";
//    string s4="   ";
//    string s10="Hello";
//    string s11="World";
//    string s12="Kemba";
//    string s13="Gambia";
//    string s14="   ";
//    NodeData *n = new NodeData(s);
//    NodeData *n1 = new NodeData(s1);
//    NodeData *n2 = new NodeData(s2);
//    NodeData *n3 = new NodeData(s3);
//    NodeData *n4 = new NodeData(s4);
//    NodeData *n10 = new NodeData(s10);
//    NodeData *n11 = new NodeData(s11);
//    NodeData *n12 = new NodeData(s12);
//    NodeData *n13 = new NodeData(s13);
//    NodeData *n14 = new NodeData(s14);
//
////    cout << "here" << endl;
////     ndArray[0]=n3;
////     ndArray[1]=n2;
////     ndArray[2]=n;
////     ndArray[3]=n1;
////     ndArray[4]=n4;
//
//cout << "Testing insert" << endl;
//    b.insert(n);
//    b.insert(n1);
//    b.insert(n2);
//    b.insert(n3);
//    //b.insert(n4);
//    b.displaySideways();
//    cout <<"B is : " << b<< endl;
//
//
//    b2 = b2 =b;
//    NodeData *n5;
//    NodeData n7("Kemba");
//    b2.makeEmpty();
//    b2=b;
//
//
//
//    cout << "Testing the copy constrcutor." << endl;
//    BinTree b3;
//    BinTree T1 (b);
//    cout << "values of T1: " << T1 <<  " values of b: " << b << endl;
//    //b2=b2;
//    b3.makeEmpty();
//
//    b.bstreeToArray(ndArray);
//    if(b.isEmpty()){
//        cout<<"B is empty"<<endl;
//    }else{
//        cout<<"B is NOT empty"<<endl; //
//    }
//
//    b4.arrayToBSTree(ndArray);
//    for(int i=0;i<100;i++){
//        if(ndArray[i]!=NULL){
//            cout <<"B3 is : "<<i <<" "<<*ndArray[i]<<endl;
//        }
//    }
//
//    cout << "Testing get height" << endl;
//    cout <<"B2 is : "<<b2<<endl;
//    cout <<"B4 is : "<<b4<<endl;
//    cout <<"B3 is : "<<b3<<endl;
//    cout <<"The Height is : "<<b.getHeight(n7)<<endl;
//
//        cout<< " TEst equal and Inequal operator " << endl;
//     if(b!=b2){
//         cout<<"B1 is NOT equal to B2"<< endl;
//
//     }else{
//       cout<<"B1 is equal to B2"<< endl;
//     }
//
//
//
//     cout << " " << endl;
//     cout << "Testing retrieve" << endl;
//
//     if(b.retrieve(n7,n5)){
//       cout << "n was found" << endl;
//       cout << " N5 is: " << *n5 << endl;
//     }else{
//       cout << "n was NOT found" << endl;
//     }
//
//    return 0;
//}
//void initArray(NodeData* ndArray[]) {
//    for (int i = 0; i < ARRAYSIZE; i++){
//        ndArray[i] = NULL;
//    }
//}
//
