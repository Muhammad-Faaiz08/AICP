#include<iostream>
using namespace std;
class TreeNode
{
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):key(value),left(nullptr),right(nullptr){}
};
class MinHeap
{
private:
    int* heap;
    int capacity;
    int size;
    void heapify(int index)
    {
        int smallest=index;
        int left=2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if(smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }
public:
    MinHeap(int cap):capacity(cap),size(0)
    {
        heap = new int[capacity];
    }
    ~MinHeap()
    {
        delete[] heap;
    }
    void insert(int key)
    {
        if (size == capacity)
        {
            cout<<"Heap overflow"<<endl;
            return;
        }
        int i=size++;
        heap[i]=key;
        while (i!=0 && heap[(i-1)/2]>heap[i])
        {
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void buildHeap(int* data,int n)
    {
        if (n>capacity)
        {
            cout<<"Heap capacity exceeded"<<endl;
            return;
        }
        for(int i=0;i<n;++i)
        {
            heap[i]=data[i];
        }
        size=n;
        for (int i=size/2-1;i>=0;--i)
        {
            heapify(i);
        }
    }

    void displayHeap()
    {
        for (int i=0;i<size;++i)
        {
            cout<<heap[i] << " ";
        }
        cout<<endl;
    }
};
void add(TreeNode*& root, int key)
{
    if (root == nullptr)
    {
        root = new TreeNode(key);
    } else if (key < root->key)
    {
        add(root->left, key);
    } else
    {
        add(root->right, key);
    }
}
void postOrder(TreeNode* root, int* result, int& index)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left, result, index);
    postOrder(root->right, result, index);
    result[index++] = root->key;
}
void preOrder(TreeNode* root, int* result, int& index)
{
    if (root == nullptr)
    {
        return;
    }
    result[index++] = root->key;
    preOrder(root->left, result, index);
    preOrder(root->right, result, index);
}
TreeNode* populateTree(int* data, int n)
{
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        add(root, data[i]);
    }
    return root;
}
int main()
{
    int n;
    cout<<"How many nodes you want to insert into BST: ";
    cin>>n;
    int* data = new int[n];
    cout << "Enter "<<n<<" values to insert into BST: ";
    for(int i=0;i<n;++i)
    {
        cin>>data[i];
    }
    cout<<endl;
    cout<<data[0]<<" is inserted as root in BST"<<endl;
    for(int j=1;j<n;++j)
    {
        cout<<data[j]<<" inserted in BST"<<endl;
    }
    cout<<endl;
    cout<<endl;
    TreeNode* bstRoot = populateTree(data, n);
    int* postOrderResult = new int[n];
    int postIndex = 0;
    postOrder(bstRoot, postOrderResult, postIndex);
    cout << "Post-order Traversal of BST: ";
    for (int i = 0; i < postIndex; ++i)
    {
        cout << postOrderResult[i] << " ";
    }
    cout << endl;
    MinHeap minHeap1(n);
    for (int i = 0; i < postIndex; ++i)
    {
        minHeap1.insert(postOrderResult[i]);
    }
    cout << "Min Heap using Insert method: ";
    minHeap1.displayHeap();
    cout<<endl;
    int* preOrderResult = new int[n];
    int preIndex = 0;
    preOrder(bstRoot, preOrderResult, preIndex);
    cout << "Pre-order Traversal of BST: ";
    for (int i = 0; i < preIndex; ++i)
    {
        cout << preOrderResult[i] << " ";
    }
    cout << endl;
    MinHeap minHeap2(n);
    minHeap2.buildHeap(preOrderResult, preIndex);
    cout << "Min Heap using Build method: ";
    minHeap2.displayHeap();
    delete[] data;
    delete[] postOrderResult;
    delete[] preOrderResult;
    return 0;
}
