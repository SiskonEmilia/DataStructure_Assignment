#include "familyTree.hpp"
//private:
//Node *root; 
//Notice: root can't be nullptr!
unsigned Node::count = 0;

familyTree::familyTree() // 默认且唯一的构造函数：创建一个带有一个根节点的家谱树 *ZJ*
{
    root = new Node(Detail("unknown","unknown","unknown","unknown",true),nullptr);
}
familyTree::~familyTree() // 析构函数，仅需delete根节点 *ZJ*
{
    delete root;
}
toReturn familyTree::addToParent(const Detail& detail, const unsigned& id) 
// 将一个包含Detail的节点设为目标节点的双亲节点
// 返回值通过调用printTree生成 *ZJ*
{
    try
    {    
        Node &son = getNode(id);
        Node father(detail,nullptr);
        son.parent = &father;//设为双亲节点既是将孩子的parent指针指向双亲，也需要双亲的childremvector把孩子push进去
        father.children.push_back(son);
        return toReturn(printTree(), false);//在添加失败的时候还没有考虑
    }
    catch(string str)
    {
        return toReturn(str, true);
    }
}
toReturn familyTree::addToCouple(const Detail& detail, const unsigned& id)
// 将一个包含Detail的节点设为目标节点的配偶节点
// 返回值通过调用printTree生成 *ZJ*
{
    try
    {
        Node &husband = getNode(id);
        Node wife(detail,nullptr);
        husband.couple.push_back(wife);
        return toReturn(printTree(),false);//在添加失败的时候还没有考虑
    }
    catch(string str)
    {
       return toReturn(str, true);
    }
}
toReturn familyTree::addToSublings(const Detail& detail, const unsigned& id)
// 将一个包含Detail的节点设为目标节点的兄弟节点
// 返回值通过调用printTree生成 *ZJ*
{
    try
    {    
        Node &bigBrother = getNode(id);
        Node littleBrother(detail,bigBrother.parent);//儿子找到了爸爸
        bigBrother.parent->children.push_back(littleBrother);//爸爸找到了儿子
        return toReturn(printTree(),false);
    }
    catch(string str)
    {
        return toReturn(str, true);
    }
}
toReturn familyTree::addToChildren(const Detail& detail, const unsigned& id)
// 将一个包含Detail的节点设为目标节点的子节点
// 返回值通过调用printTree生成 *ZJ*
{
    try
    {    
        Node &father = getNode(id);
        Node son(detail,nullptr);
        father.children.push_back(son);//爸爸找到了儿子
        son.parent = &father;//儿子找到了爸爸
        return toReturn(printTree(),false);
    }
    catch(string str)
    {
        return toReturn(str, true);
    }
}

toReturn familyTree::deleteSubTree(const unsigned& id)
// 删除id指定节点为根的子树
// 返回值通过调用printTree生成 *ZJ*
{
    try
    {   
        if(id == 0)
        {
            throw "Cannot delete the root";
        }
        Node& aim = getNode(id);
        vector<Node>::iterator iter;
        for(iter = aim.parent->children.begin();iter != aim.parent->children.end();)
        {
            if(iter->id == id)
            {
                iter = aim.parent->children.erase(iter);
                break;
            }
            else
                iter++;
        }
        aim.parent = nullptr;
        return toReturn(printTree(),false);
    }
    catch(string str)
    {
        return toReturn(str, true);
    }
}

Node* traverse(Node* person, const unsigned& id)
{
    if (person->id == id)
        return person;
    Node *temp;
    
    if (person->couple.size() != 0) {
        for (unsigned i = 0; i < person->couple.size(); ++i) {
            if ((temp = traverse(&(person->couple[i]), id)) != nullptr)
                return temp;
        }
    }

    if (person->children.size() != 0) {
        for (unsigned i = 0; i < person->children.size(); ++i) {
            if ((temp = traverse(&(person->children[i]), id)) != nullptr)
                return temp;
        }
    }

    return nullptr;
}

Node& familyTree::getNode(const unsigned& id)
// 获取id指定节点的引用，若未找到，则 throw "NODE_NOT_FOUND"
// 使用时需要try & catch *ZJ*
{
    auto temp = traverse(root, id);
    if (temp == nullptr)
        throw "NODE_NOT_FOUND";
    return *temp;
}
string familyTree::nodeToString(Node &root) {
	vector<Node>::iterator itr = root.children.begin();
	string ans = "";
	if (itr == root.children.end()) {
		ans = ans + "<ul><li>" + "<span id=\"" + to_string(root.id) 
			+ "\" class=\"" + to_string(root.detail.isMale) + "\">" 
			+ root.detail.firstName + root.detail.lastName + "</span>" + "</li></ul>";
	} else {
		ans = ans + "<ul><li>" + "<span id=\"" + to_string(root.id) 
			+ "\" class=\"" + to_string(root.detail.isMale) + "\">" 
			+ root.detail.firstName + root.detail.lastName + "</span>";

		for (itr = root.couple.begin(); itr != root.couple.end(); ++itr) {
			ans = ans + "<span id=\"" + to_string(root.id) 
				+ "\" class=\"" + to_string(root.detail.isMale) + "\">" 
				+ (itr->detail).firstName + (itr->detail).lastName + "</span>";
		}

		for (itr = root.children.begin(); itr != root.children.end(); ++itr) {
			ans += nodeToString(*itr);
		}

		ans += "</li></ul>";
	}
	return ans;
}

string familyTree::printTree() {
	string ans = nodeToString(*root);
	return ans;
}
