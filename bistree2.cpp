#include<iostream>
using namespace std;

class Node{
  public:
   int data;
   Node*left;
   Node*right;
   Node*parent;
  
   Node(int val) {
     left=NULL;
     right=NULL;
     parent=NULL;
     data=val;
    }
  };

class bist {
   public:
  Node*root;
  
  bist(){
   root=NULL;
   }


void insert(int val){
    insertHelper(root,val);
  }

void insertHelper(Node*current,int val){
     if(current==NULL){
        if(root==NULL){
          current=new Node(val);
          root=current;
         }
       }
      else if(val>current->data){
          if (current->right==NULL){
            current->right=new Node(val);
            (current->right)->parent=current;
              }
          else  {
            insertHelper(current->right,val);
            }
         }
      else  {
         if(current->left==NULL){
            current->left=new Node(val);
            (current->left)->parent=current;
            }
         else {
          insertHelper(current->left,val);
            }
          }
       }

void display(){
  display2(root);
   }

void display2(Node*current){
   if(current->left!=NULL){
      display2(current->left);
    }
     cout<<current->data<<",";
   if(current->right!=NULL){
      display2(current->right);
    }
  }

Node*find_min(Node*current){
  while(current->left!=NULL){
    current=current->left;
   }
  return current;
 }

void deletenode(int val) {
  deletehelper(root,val);
  }

Node*deletehelper(Node*current,int val){
   if (current==NULL){
      return current;
    }
   if (val<current->data) {
     current->left = deletehelper(current->left,val);
   }
   else if(val>current->data) {
      current->right = deletehelper(current->right,val);
   }
  else {
     if(current->left==NULL) {
        Node*temp = current->right;
        delete current;
        return temp;
       }
     else if(current->right==NULL){
        Node*temp = current->left;
        delete current;
        return temp;
       }
     else {
         Node* temp= find_min(current->right);
         current->data=temp->data;
         current->right = deletehelper(current->right,temp->data);
      }
     return current;
  }
}

int counter() {
  counter2(root);
}

int counter2(Node*current) {
   int i=1;
  if(current->left!=NULL) {
    i=i+counter2(current->left);
    }
  if(current->right!=NULL){
    i=i+counter2(current->right);
   }
     return i;
   }

int height() {
   height2(root);
  }

int height2(Node*current) {
   
   int ldepth;
   int rdepth;
  if (current==NULL){
    return 0;
   }
  else {
    ldepth = height2(current->left);
    rdepth = height2(current->right);
   }
   if(ldepth>rdepth){
     return(ldepth+1);
    }
   else {
     return(rdepth+1);
    }
}

int rangeSearch(int k1,int k2) {
    range2(root,k1,k2);
  }

int range2 (Node*current,int k1,int k2) {
   if(current==NULL) {
       return 0;
      }
   if(k1 < current->data) {
     range2(current->left,k1,k2);
    }
     
   if(k1<=current->data && k2>=current->data){
      cout<< current->data<<",";
    }
   if(k2 > current->data){
     range2(current->right,k1,k2);
    }
  }

int rangecount(int k1,int k2) {
     count2(root,k1,k2);
   }

int count2(Node*current,int k1,int k2) {
  if(current==NULL){
     return 0;
   }
  
  if (current->data>=k1 && current->data<=k2){
      return 1+ count2(current->left,k1,k2)+count2(current->right,k1,k2);
     }
  else if (current->data<k1) {
      count2(current->right,k1,k2);
     }
  else {
      count2(current->left,k1,k2);
     }
  }
 };

int main(){

bist s1;
s1.insert(23);
s1.insert(20);
s1.insert(19);
s1.insert(25);
s1.insert(33);
s1.insert(15);
s1.insert(45);
s1.insert(16);
s1.display();
  int a,b;
 cout<<"the boundary numbers of the range:";
 cin>>a>>b;
 cout<<endl;
 cout<<s1.rangeSearch(a,b);
 cout<<endl;
 cout<<"the number of nodes in this range is:"<<s1.rangecount(a,b)<<endl;

int s;
cout<<"what do you want to delete?"<<endl;
cin>>s;
cout<<endl;
  
s1.deletenode(s);
cout<<endl;
s1.display();
  cout<<endl;
 cout<<"total number of nodes are:"<<s1.counter()<<endl;
 cout<<"the height of binary search tree:"<<s1.height()<<endl;

 

return 0;
}
