#ifndef __TREE__P
#define __TREE__P

#include "head.h"

template<typename T> interface ITree {
	virtual T& getData() = 0;
	virtual void setData(T* data) = 0;
	virtual void setData(T data) = 0;
	virtual string getType() = 0;
	virtual vector<ITree<T>*> getChildren() = 0;
	virtual ITree<T>* getParent() = 0;
	virtual ITree<T>* addChild(ITree<T>* node) = 0;
	virtual ITree<T>* addChild(T* data) = 0;
	virtual ITree<T>* addChild(T data) = 0;
	template<typename F1, typename F2, typename F3>void foreach(F1 function, F2 onNextLevel, F3 onLastLevel) {
		function(this);
		onNextLevel(this);
		vector<ITree*> nodes = getChildren();
		for (ITree* node : nodes) {
			node->foreach(function, onNextLevel, onLastLevel);
		}
		onLastLevel(this);
	}
};

template<typename T> abstract class BaseTree : public ITree<T>{
protected:
	T* data;
	bool isNew;
	const string type;
public:
	virtual T& getData() override{
		return *data;
	}
	virtual void setData(T* data) override {
		if (isNew) {
			delete data;
			isNew = false;
		}
		this->data = data;
	}
	virtual void setData(T data) override {
		*(this->data) = data;
	}
	virtual string getType() override {
		return type;
	}
	BaseTree(T* data, string type) {
		this->data = data;
		this->type = type;
		isNew = false;
	}
	BaseTree(T data, string type) {
		this->data = new T(data);
		this->type = type;
		isNew = true;
	}
	virtual ~BaseTree() {
		vector<ITree<T>*> nodes;
		if (isNew) {
			delete data;
		}
		for (ITree<T>* node : nodes) {
			delete node;
		}
	}
};

template<typename T> class NormalTree : public BaseTree<T>{
protected:
	ITree<T>* parent;
	vector<ITree<T>*> children;
public:
	NormalTree(T* data, ITree<T>* parent) : BaseTree<T>(data, string("normal")) {
		this->parent = parent;
	}
	NormalTree(T data, ITree<T>* parent) : BaseTree<T>(data, string("normal")) {
		this->parent = parent;
	}
	virtual vector<ITree<T>*> getChildren() override {
		return children;
	}
	virtual ITree<T>* getParent() override {
		return parent;
	}
	virtual ITree<T>* addChild(ITree<T>* node) override {
		children.push_back(node);
		return node;
	}
	virtual ITree<T>* addChild(T* data) override {
		return addChild(new NormalTree<T>(data, this));
	}
	virtual ITree<T>* addChild(T data) override {
		return addChild(new NormalTree<T>(data, this));
	}
};

template<typename T> class BinTree : public BaseTree<T>{
protected:
	ITree<T>* parent;
	ITree<T>* left;
	ITree<T>* right;
public:
	BinTree(T* data, ITree<T>* parent) : BaseTree<T>(data, string("bin")) {
		this->parent = parent;
	}
	BinTree(T data, ITree<T>* parent) : BaseTree<T>(data, string("bin")) {
		this->parent = parent;
	}
	virtual vector<ITree<T>*> getChildren() override {
		vector<ITree<T>*> children;
		if (left != NULL) {
			children.push_back(left);
		}
		if (right != NULL) {
			children.push_back(right);
		}
		return children;
	}
	virtual ITree<T>* getParent() override {
		return parent;
	}
	
	virtual ITree<T>* addLeft(ITree<T>* node) {
		left = node;
		return left;
	}
	virtual ITree<T>* addLeft(T* data) {
		return addLeft(new BinTree<T>(data, this));
	}
	virtual ITree<T>* addLeft(T data) {
		return addLeft(new BinTree<T>(data, this));
	}
	
	virtual ITree<T>* addRight(ITree<T>* node) {
		right = node;
		return right;
	}
	virtual ITree<T>* addRight(T* data) {
		return addRight(new BinTree<T>(data, this));
	}
	virtual ITree<T>* addRight(T data) {
		return addRight(new BinTree<T>(data, this));
	}
	
	virtual ITree<T>* getRight() {
		return right;
	}
	
	virtual ITree<T>* getLeft() {
		return left;
	}
	/*------------------------*/
	virtual ITree<T>* addChild(ITree<T>* node) override {
		left = node;
		return this;
	}
	virtual ITree<T>* addChild(T* data) override {
		return addChild(new BinTree<T>(data, this));
	}
	virtual ITree<T>* addChild(T data) override {
		return addChild(new BinTree<T>(data, this));
	}
	
	template<typename F1>void vlrforeach(F1 function) {
		function(this);
		if (this.left->getType() == "bin") {
			((BinTree)this.left)->vlrforeach();
		}
		else {
			this.left->foreach();
		}
		if (this.right->getType() == "bin") {
			((BinTree)this.right)->vlrforeach();
		}
		else {
			this.right->foreach();
		}
	}
	template<typename F1>void ldrforeach(F1 function) {
		if (this.left->getType() == "bin") {
			((BinTree)this.left)->vlrforeach();
		}
		else {
			this.left->foreach();
		}
		function(this);
		if (this.right->getType() == "bin") {
			((BinTree)this.right)->vlrforeach();
		}
		else {
			this.right->foreach();
		}
	}
	template<typename F1>void lrdforeach(F1 function) {
		if (this.left->getType() == "bin") {
			((BinTree)this.left)->vlrforeach();
		}
		else {
			this.left->foreach();
		}
		if (this.right->getType() == "bin") {
			((BinTree)this.right)->vlrforeach();
		}
		else {
			this.right->foreach();
		}
		function(this);
	}
};

#endif
