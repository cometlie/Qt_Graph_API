#ifndef GRAPHLINK_H
#define GRAPHLINK_H

#include"dblinkedlist.h"
#include"expandablelinkedhashtable.h"
#include"hashmap.h"

/******声明要用到的结构体*******/
template<typename K , typename W>
struct Edge;
template<typename K , typename W>
struct Vertex;
template<typename K , typename W>
struct Neighbors;

/***************************/

template<typename K , typename W>
struct Edge{
    DblNode<K , Vertex<K , W>> *vp; //指向另一个顶点的指针
    DblNode<W , Edge<K , W>> *frien_p;  //伙伴指针
    W _cost; //权值
    Edge<K , W>(DblNode<K , Vertex<K , W>> *vpoint = NULL , DblNode<W , Edge<K , W>> *frien_point = NULL)
        : vp(vpoint) , frien_p(frien_point){}
    Edge<K , W>(W cost, DblNode<K , Vertex<K , W>> *vpoint = NULL , DblNode<W , Edge<K , W>> *frien_point = NULL)
        : _cost(cost) , vp(vpoint) , frien_p(frien_point){}
};

template<typename K , typename W>
struct Vertex{
    int data; //顶点数据
    int degree;//顶点的度
    DbLinkedList<W , Edge<K , W>> EdgeList;//顶点的边链表
    Vertex<K , W>()
        : data(NULL) , degree(0){}
    Vertex<K , W>(int dat)
        : data(dat) , degree(0){}
};

template<typename K , typename W>
struct VertexForHash{
    K key;//插入哈希映射中的关键码
    int data;//顶点整数值
    DblNode<K , Vertex<K , W>> *pos;

};

template<typename K , typename W>
struct EdgeForHash{

};


template<typename K , typename W>
struct Neighbors{
    DbLinkedList<K , Vertex<K , W>> neiborList;//存储邻接点
    DbLinkedList<W , W> costList; //存储对应权值
};


template<typename K , typename W>
class WUSGraph
{
public:
    WUSGraph(int v);//用v个顶点和0条边初始化一个空图
    int vertexCount();//返回图中顶点的个数
    int edgeCount();//返回图中边的个数
    Vertex<K , W> *getVertices();//返回包含所有顶点的数组
    void addVertex(Vertex<K , W> ver);//添加顶点
    void removeVertex(Vertex<K , W> ver);//删除顶点
    bool isVertex(Vertex<K , W> ver);//判断该顶点是否在图中
    int Degree(Vertex<K , W> ver);//顶点的度
    Neighbors<K , W> getNeighbors(Vertex<K , W> ver);//返回顶点的所有邻接顶点
    void addEdge(Vertex<K , W> ver1 , Vertex<K , W> ver2 , W cost);//添加边
    void removeEdge(Vertex<K , W> ver1 , Vertex<K , W> ver2);//删除边
    bool isEdge(Vertex<K , W> ver1 , Vertex<K , W> ver2);//判断边是否在图中
    W getWeight(Vertex<K , W> ver1 , Vertex<K , W> ver2);//求某边的权值
private:
    HashMap<K , Vertex<K , W>> verMap;//顶点散列映射
    HashMap<K , Edge<K , W>> edgMap;//边散列映射
    DbLinkedList<K , Vertex<K , W>> verList;//顶点双链表
    int vertexNum;//顶点数量
    int edgeNum;//边数量
    DblNode<K , W> isVertex(K key);

};

#endif // GRAPHLINK_H
