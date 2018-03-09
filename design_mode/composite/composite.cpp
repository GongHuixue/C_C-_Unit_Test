/*
 * Copyright (c) 2014.  lin_jie_long@126.com, Mon 26 Oct 2015 11:38:28 AM CST,  All rights reserved.
 */
/*
 * File Name:  composite.cpp
 * Author:     Vanqusier(lin_jie_long@126.com)
 * EMail:      lin_jie_long@126.com
 */

/* 
    组合模式:将对象组合成树形结构以表示“部分-整体”的层次结构，组合模式使得用用户对单个对象和 
    组合对象的使用具有一致性。 
    Created by Phoenix_FuliMa 
*/  
  
#include <iostream>  
#include <string>  
#include <list>  
#include <stdlib.h>  
using namespace std;  
  
class Component  
{  
protected:  
    string name;  
public:  
    Component(string name)  
        :name(name)  
    {   } 
    virtual void AddComponent(Component *component) {   }  
    virtual void RemoveComponent(Component *component)  {   }  
    virtual void GetChild(int depth)    { }  
};  
  
class Leaf: public Component  
{  
public:  
    Leaf(string name)  
        :Component(name)  
    {   }  
    void AddComponent(Component *component)  
    {  
        cout<<"Leaf can't add component"<<endl;  
    }  
    void RemoveComponent(Component *component)  
    {  
        cout<<"Leaf can't remove component"<<endl;  
    }  
    void GetChild(int depth)  
    {  
        string _tmpstring(depth, '-');  
        cout<<_tmpstring<<name<<endl;  
    }  
};  
  
class Composite:public Component  
{  
private:  
    list<Component*> _componets;  
  
public:  
    Composite(string name)  
        :Component(name)  
    { }  
    void AddComponent(Component *component)  
    {  
        _componets.push_back(component);  
    }  
    void RemoveComponent(Component *component)  
    {  
        _componets.remove(component);  
    }  
    void GetChild(int depth)  
    {  
        string tmpstring (depth, '-');  
        cout<<tmpstring<<name<<endl;  
        list<Component*>::iterator iter = _componets.begin();  
        for(; iter != _componets.end(); iter++)  
        {  
            (*iter)->GetChild(depth + 2);  
        }  
    }  
};  
  
int main()  
{  
    Composite *root = new Composite("root");  
    Leaf *leaf1 = new Leaf("leaf1");  
    Leaf *leaf2 = new Leaf("leaf2");  
    root->AddComponent(leaf1);  
    root->AddComponent(leaf2);  
  
    Composite *lay2 = new Composite("layer2");  
    Leaf *leaf4 = new Leaf("leaf4");  
    lay2->AddComponent(leaf4);  
  
    Composite *lay1 = new Composite("layer1");  
    Leaf *leaf3 = new Leaf("leaf3");  
    lay1->AddComponent(leaf3);  
    lay1->AddComponent(lay2);  
  
    root->AddComponent(lay1);  
  
    root->GetChild(1);  
    cout<<endl;  
    lay1->GetChild(1);  
    cout<<endl;  
    lay2->GetChild(1);  
  
    delete root;  
    delete lay1;  
    delete lay2;  
    delete leaf1;  
    delete leaf2;  
    delete leaf3;  
    delete leaf4;  
	//getch();
    system("pause");  
    return 0;  
} 
