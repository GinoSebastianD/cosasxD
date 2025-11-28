#include <iostream>
#include "queue"
#include <thread>
#include<mutex>
#include<vector>
struct CNode
{
    CNode(int _v)
    {
        v = _v; nodes[0] = nodes[1] = 0;
    }
    int v;
    CNode* nodes[2];
};

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool find(int x, CNode**& p);
    bool ins(int x);
    bool rem(int x);
    CNode** rep(CNode** p);
    void inorder(CNode* n);
    
    //---------------------------------------------------------------------------
    void sum_inorder(CNode* root);
    void level2(int nivel, std::vector<CNode*>& local_sum);

    CNode* getroot() {
        return root;
    }
    void sum_subtree(CNode* root, int& result);
    //---------------------------------------------------------------------------

    
    int sum = 0;
    std::mutex m;

    int level(CNode* n);

private:
    CNode* root;
    bool brep;
};

CBinTree::CBinTree()
{
    root = 0;   brep = 0;
}

CBinTree::~CBinTree()
{
}

bool CBinTree::find(int x, CNode**& p)
{
    for (p = &root; *p && (*p)->v != x;
        p = &((*p)->nodes[(*p)->v < x]));
    return *p != 0;
}
bool CBinTree::ins(int x)
{
    CNode** p;
    if (find(x, p)) return 0;
    *p = new CNode(x);
    return 1;
}

bool CBinTree::rem(int x)
{
    CNode** p;
    if (!find(x, p)) return 0;

    if ((*p)->nodes[0] && (*p)->nodes[1])//caso 2
    {
        CNode** q = rep(p);
        (*p)->v = (*q)->v;
        p = q;
    }
    CNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[1] != 0];
    delete t;
    return 1;
}

CNode** CBinTree::rep(CNode** p)
{
    CNode** q = p;
    for (q = &((*q)->nodes[!brep]); (*q)->nodes[brep];
        q = &((*q)->nodes[brep]));
    brep = !brep;
    return q;
}



void CBinTree::inorder(CNode* n)
{
    if (!n) return;
    inorder(n->nodes[0]);
    std::cout << n->v << " ";
    inorder(n->nodes[1]);
}

int CBinTree::level(CNode* n)
{
    if (!n) return 0;
    std::queue<CNode*> c;
    c.push(n);

    while (!c.empty())
    {
        CNode* x = c.front();
        std::cout << x->v << "\n";
        if (x->nodes[0])
        {
            c.push(x->nodes[0]);
        }
        if (x->nodes[1])
        {
            c.push(x->nodes[1]);
        }
        c.pop();
    }
    return 1;
}


void CBinTree::level2(int nivel , std::vector<CNode*>& out)
{
    if (!root) return;
    std::queue< std::pair<CNode*, int> > c;
    c.push({ root,n });
    while (!c.empty())
    {

        CNode* x = c.front().first;
        int actual = c.front().second;
        c.pop();
        if ( actual== nivel)
        {
            out.push_back(x);
        }   
        if (actual >= nivel)
            continue;

        if (x->nodes[0])
        {
            c.push({ x->nodes[0],actual+1 });
        }
        if (x->nodes[1])
        {
            c.push({ x->nodes[1],actual+1});
        }
    }
    return;
}

void CBinTree::sum_inorder(CNode* root)
{
    if (!root)
    {
        return;
    }
    sum_inorder(root->nodes[0]);
    sum = sum + root->v;
    sum_inorder(root->nodes[1]);
}
void CBinTree::sum_subtree(CNode* root, int& result)
{
    if (!root) return;
    sum_subtree(root->nodes[0], result);
    result += root->v;
    sum_subtree(root->nodes[1], result);
}
int main()
{
    CBinTree t;

    t.ins(60); t.ins(30); t.ins(70); 
    t.ins(20); t.ins(40); t.ins(65);
    t.ins(80); t.ins(75); t.ins(10);
    t.ins(5);  t.ins(3);  t.ins(2);
    t.ins(1);  t.ins(0);  t.ins(-1);
    t.ins(-2); t.ins(90); t.ins(95);
    t.ins(97); t.ins(99);
    std::vector<CNode*> subtrees;
    t.level2(3, subtrees);

    std::vector<int> local_sum(4);
    std::vector<std::thread> vec(4);
    int nivel = 4;
    for (int i = 0 ; i < 4 ; i++)
    {
        vec[i] = std::thread(&CBinTree::sum_subtree, &t, subtrees[i], std::ref(local_sum[i]));
    }



    for (int i = 0; i < 4; i++)
        vec[i].join();

    int sum_total = 0;
   sum_total = sum_total + t.getroot()->v + t.getroot()->nodes[0]->v + t.getroot()->nodes[1]->v;
   std::cout << sum_total << " ";

   for (int i = 0 ; i < 4 ; i++)
   {
       sum_total = sum_total + local_sum[i];
   }
   std::cout << sum_total << " ";

    


}
