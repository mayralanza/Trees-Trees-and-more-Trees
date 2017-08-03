template<class Type>
class TreeNode{
private:
	int key;
    Type data;
public:
  /*  TreeNode():valid(false),parent(0),first_child(0),next_sibling(0){
    }
   */
	TreeNode(const int & key, const Type & data){
		this->key = key;
		this->data = data;
	}

	TreeNode(){
	}

	int getKey(){
		return this->key;
	}

	Type getData(){
		return this->data;
	}
////////////////////////////////
}; // class-end
