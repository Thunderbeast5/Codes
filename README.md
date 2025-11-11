# DSAL - Data Structures and Algorithms Laboratory

## Table of Contents
1. [01(list).cpp - Flight Management (Adjacency List)](#01listcpp)
2. [01(matrix).cpp - Flight Management (Adjacency Matrix)](#01matrixcpp)
3. [02(bst).cpp - Binary Search Tree](#02bstcpp)
4. [03(expression).cpp - Expression Tree (Prefix)](#03expressioncpp)
5. [03(multiple exp).cpp - Multiple Expression Trees](#03multiple-expcpp)
6. [03(postfix).cpp - Expression Tree (Postfix)](#03postfixcpp)
7. [04(avl).cpp - AVL Tree Dictionary](#04avlcpp)
8. [05(fractional).cpp - Fractional Knapsack](#05fractionalcpp)
9. [06(0-1 branch).cpp - 0/1 Knapsack (Branch & Bound)](#060-1-branchcpp)
10. [06(0-1 dp).cpp - 0/1 Knapsack (Dynamic Programming)](#060-1-dpcpp)
11. [07(heap marks).cpp - Heap (Student Marks)](#07heap-markscpp)
12. [07(heap).cpp - Heap (Stock Prices)](#07heapcpp)

---

## 01(list).cpp
**Flight Management System using Adjacency List**

### Overall Complexity
- **Time Complexity:** O(V + E) for graph representation
- **Space Complexity:** O(V + E)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `Node()` constructor | O(1) | Creates a new node |
| `Graph()` constructor | O(V) | Initializes 20 head pointers |
| `readGraph()` | O(V + E) | Reads vertices and edges |
| `checkDirectFlight()` | O(E) | Checks for direct connection (worst case) |
| `displayAllFlights()` | O(V + E) | Displays all adjacency lists |
| `countTotalFlights()` | O(E) | Counts outgoing edges from a vertex |
| `showCities()` | O(V) | Displays all cities |
| `printAllRoutesUtil()` | O(V! × V) | DFS-based path finding (exponential) |
| `printAllRoutes()` | O(V! × V) | Wrapper for printAllRoutesUtil |
| `reachableCitiesUtil()` | O(V + E) | DFS traversal |
| `reachableCities()` | O(V + E) | Wrapper for reachableCitiesUtil |

**Where:**
- V = Number of vertices (cities)
- E = Number of edges (flights)

---

## 01(matrix).cpp
**Flight Management System using Adjacency Matrix**

### Overall Complexity
- **Time Complexity:** O(V²) for graph representation
- **Space Complexity:** O(V²)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `Graph()` constructor | O(V²) | Initializes two V×V matrices |
| `readGraph()` | O(V + E) | Reads vertices and edges |
| `showCities()` | O(V) | Displays all cities |
| `displayMatrix()` | O(V²) | Displays time and fuel matrices |
| `checkDirectFlight()` | O(1) | Direct array access |
| `countFlightsFromCity()` | O(V) | Counts non-zero entries in row |
| `printAllRoutesUtil()` | O(V! × V²) | DFS with matrix traversal |
| `printAllRoutes()` | O(V! × V²) | Wrapper function |
| `reachableCitiesUtil()` | O(V²) | DFS in matrix representation |
| `reachableCities()` | O(V²) | Wrapper function |

**Comparison with Adjacency List:**
- Matrix uses more space: O(V²) vs O(V + E)
- Matrix has faster edge lookup: O(1) vs O(E)

---

## 02(bst).cpp
**Binary Search Tree Operations**

### Overall Complexity
- **Time Complexity (Average):** O(log n) for most operations
- **Time Complexity (Worst):** O(n) for skewed tree
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity (Avg) | Time Complexity (Worst) | Description |
|----------|--------------------|----------------------|-------------|
| `createNode()` | O(1) | O(1) | Creates new node |
| `insert()` | O(log n) | O(n) | Inserts node recursively |
| `height()` | O(n) | O(n) | Visits all nodes |
| `findMin()` | O(log n) | O(n) | Traverses leftmost path |
| `search()` | O(log n) | O(n) | Binary search in tree |
| `printAscending()` | O(n) | O(n) | Inorder traversal |
| `printAscendingNonRec()` | O(n) | O(n) | Iterative inorder |
| `printDescending()` | O(n) | O(n) | Reverse inorder |
| `printDescendingNonRec()` | O(n) | O(n) | Iterative reverse inorder |
| `countLeafNodes()` | O(n) | O(n) | Visits all nodes |
| `countInternalNodes()` | O(n) | O(n) | Visits all nodes |
| `countTotalNodes()` | O(n) | O(n) | Visits all nodes |

**Space Complexity Analysis:**
- Recursive calls stack: O(h) where h = height
- Non-recursive traversals: O(h) for stack

---

## 03(expression).cpp
**Expression Tree from Prefix Expression**

### Overall Complexity
- **Time Complexity:** O(n) where n = length of expression
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `createNode()` | O(1) | Creates new node |
| `isOperator()` | O(1) | Character check |
| `constructTree()` | O(n) | Processes each character once |
| `inorder()` | O(n) | Visits all n nodes |
| `preorder()` | O(n) | Visits all n nodes |
| `postorder()` | O(n) | Visits all n nodes |
| `inorderNonRec()` | O(n) | Iterative traversal |
| `preorderNonRec()` | O(n) | Iterative traversal |
| `postorderNonRec()` | O(n) | Uses two stacks |
| `swapTree()` | O(n) | Visits all nodes |
| `countLeafNodes()` | O(n) | Visits all nodes |
| `countInternalNodes()` | O(n) | Visits all nodes |
| `countTotalNodes()` | O(n) | Visits all nodes |

**Space Complexity Analysis:**
- Tree storage: O(n)
- Stack for construction: O(n)
- Recursive traversal stack: O(h) where h = height
- Non-recursive traversal: O(n) for stacks

---

## 03(multiple exp).cpp
**Multiple Expression Trees Management**

### Overall Complexity
- **Time Complexity:** O(m × n) where m = number of trees, n = avg tree size
- **Space Complexity:** O(m × n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `createNode()` | O(1) | Creates new node |
| `isOperator()` | O(1) | Character check |
| `constructTree()` | O(n) | Processes expression of length n |
| `inorder()` | O(n) | Traverses tree |
| `preorder()` | O(n) | Traverses tree |
| `postorder()` | O(n) | Traverses tree |
| `mirrorTree()` | O(n) | Swaps all nodes |
| `height()` | O(n) | Visits all nodes |
| `countOperators()` | O(n) | Visits all nodes |
| Display all trees | O(m × n) | Traverses m trees |
| Compare heights | O(m × n) | Calculates height for m trees |
| Find max operators | O(m × n) | Counts operators in m trees |

**Where m = number of trees stored (max 10)**

---

## 03(postfix).cpp
**Expression Tree from Postfix Expression**

### Overall Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `createNode()` | O(1) | Creates new node |
| `isOperator()` | O(1) | Character check |
| `constructTree()` | O(n) | Processes postfix expression |
| `inorder()` | O(n) | Traversal with parentheses |
| `preorder()` | O(n) | Traversal |
| `postorder()` | O(n) | Traversal |
| `inorderNonRec()` | O(n) | Iterative inorder |
| `preorderNonRec()` | O(n) | Iterative preorder |
| `postorderNonRec()` | O(n) | Two-stack approach |
| `evaluate()` | O(n) | Post-order evaluation |
| `toPrefix()` | O(n) | Preorder traversal |
| `toInfix()` | O(n) | Inorder traversal |
| `height()` | O(n) | Visits all nodes |

**Space Complexity Analysis:**
- Construction stack: O(n)
- Non-recursive stacks: O(n)
- Recursion depth: O(h) where h = height

---

## 04(avl).cpp
**AVL Tree Dictionary (Self-Balancing BST)**

### Overall Complexity
- **Time Complexity:** O(log n) for all operations (guaranteed)
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `height()` | O(n) | Recursively calculates height |
| `BalanceFactor()` | O(n) | Uses height function |
| `rotate_right()` | O(1) | Single rotation |
| `rotate_left()` | O(1) | Single rotation |
| `LL()` | O(1) | Right rotation |
| `LR()` | O(1) | Left-Right rotation (2 rotations) |
| `RR()` | O(1) | Left rotation |
| `RL()` | O(1) | Right-Left rotation (2 rotations) |
| `insert()` | O(log n) | Insertion with balancing |
| `inorder()` | O(n) | Traverses all nodes |
| `descending()` | O(n) | Reverse inorder |
| `search()` | O(log n) | Guaranteed balanced search |
| `findMin()` | O(log n) | Leftmost node in balanced tree |
| `deleteNode()` | O(log n) | Deletion with rebalancing |

**AVL Tree Properties:**
- Height always balanced: h = O(log n)
- Rotation operations: O(1)
- Guarantees O(log n) for search, insert, delete

**Space Complexity:**
- Tree storage: O(n)
- Recursive stack: O(log n) due to balanced height

---

## 05(fractional).cpp
**Fractional Knapsack (Greedy Algorithm)**

### Overall Complexity
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `Item()` constructor | O(1) | Initializes item |
| `cmp()` | O(1) | Comparator function |
| `fractionalKnapsack()` | O(n log n) | Sort + greedy selection |
| Input items | O(n) | Read n items |

**Detailed Analysis of fractionalKnapsack():**
1. `sort(arr, arr + n, cmp)` → O(n log n)
2. Greedy loop → O(n)
3. **Total:** O(n log n) + O(n) = O(n log n)

**Space Complexity:**
- Item array: O(n)
- Sort uses: O(log n) stack space

---

## 06(0-1 branch).cpp
**0/1 Knapsack using Branch and Bound**

### Overall Complexity
- **Time Complexity:** O(2ⁿ) worst case, pruned significantly
- **Space Complexity:** O(2ⁿ) for queue storage

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `bound()` | O(n) | Calculates upper bound |
| Sorting items | O(n²) | Bubble sort used |
| Branch & Bound main loop | O(2ⁿ) | Explores state space tree |

**Detailed Analysis:**
1. Input: O(n)
2. Calculate ratios: O(n)
3. Sorting: O(n²) with bubble sort
4. Branch & Bound: O(2ⁿ) worst case
   - Each item: include or exclude (2 choices)
   - Pruning reduces actual nodes explored
5. Each node processes bound(): O(n)

**Space Complexity:**
- Item array: O(n)
- Queue: O(2ⁿ) worst case, typically much less due to pruning
- Visited array: O(n)

**Note:** Branch & Bound is more efficient than brute force O(2ⁿ) due to pruning, but worst-case remains exponential.

---

## 06(0-1 dp).cpp
**0/1 Knapsack using Dynamic Programming**

### Overall Complexity
- **Time Complexity:** O(n × W) - Pseudo-polynomial
- **Space Complexity:** O(n × W)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| Input reading | O(n) | Read n items |
| DP table construction | O(n × W) | Fill n×W table |
| DP table display | O(n × W) | Print all entries |
| Backtracking | O(n) | Find selected items |
| Output results | O(n) | Display selected items |

**Detailed Analysis:**
1. **DP Table Construction:**
   - Outer loop: n iterations
   - Inner loop: W iterations
   - **Total:** O(n × W)

2. **Backtracking:**
   - Traverse from dp[n][W] to dp[0][0]
   - At most n steps
   - **Total:** O(n)

**Space Complexity:**
- DP table: O(n × W) - Stores subproblem solutions
- Input arrays: O(n)
- **Total:** O(n × W)

**Where:**
- n = number of items
- W = knapsack capacity

**Note:** This is a pseudo-polynomial algorithm (polynomial in numeric value of input, not input size).

---

## 07(heap marks).cpp
**Max Heap for Student Marks Management**

### Overall Complexity
- **Time Complexity:** O(n log n) for heap sort
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `heapify()` | O(log n) | Maintains heap property |
| `buildHeap()` | O(n) | Bottom-up heap construction |
| `deleteMax()` | O(log n) | Remove root and heapify |
| `display()` | O(n) | Print all elements |
| `findMin()` | O(n) | Linear search in max heap |
| `heapSort()` | O(n log n) | Sorting using heap |
| Insert operation | O(log n) | Insert + buildHeap |

**Detailed Analysis:**

1. **heapify():** O(log n)
   - Recursively moves down tree
   - Height of tree = log n

2. **buildHeap():** O(n)
   - Although heapify is O(log n), bottom-up construction is O(n)
   - Mathematical proof: Σ(h=0 to log n) [n/2^(h+1) × h] = O(n)

3. **deleteMax():** O(log n)
   - Replace root with last element: O(1)
   - Heapify from root: O(log n)

4. **findMin():** O(n)
   - Min element in max heap can be any leaf
   - Must check all leaves

5. **heapSort():** O(n log n)
   - Build heap: O(n)
   - Extract max n times: n × O(log n) = O(n log n)
   - **Total:** O(n) + O(n log n) = O(n log n)

**Space Complexity:**
- Array storage: O(n)
- Temporary array for sorting: O(n)
- Recursive stack for heapify: O(log n)
- **Total:** O(n)

**Heap Properties:**
- Complete binary tree
- Max heap: Parent ≥ Children
- Height: O(log n)

---

## 07(heap).cpp
**Max Heap for Stock Prices Management**

### Overall Complexity
- **Time Complexity:** O(n log n) for heap sort
- **Space Complexity:** O(n)

### Function-wise Time Complexity

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `heapify()` | O(log n) | Maintains max heap property |
| `buildHeap()` | O(n) | Bottom-up construction |
| `deleteMax()` | O(log n) | Remove and restructure |
| `display()` | O(n) | Display all prices |
| `findMin()` | O(n) | Linear search for minimum |
| Heap sort (case 5) | O(n log n) | Complete heap sort |
| Insert operation | O(log n) | Add element + rebuild heap |

**Detailed Analysis:**

Same as `07(heap marks).cpp` - this is essentially the same heap implementation applied to stock prices instead of student marks.

**Key Operations:**
1. **Insertion:** O(log n)
2. **Find Maximum:** O(1) - root element
3. **Find Minimum:** O(n) - must search all leaves
4. **Delete Maximum:** O(log n)
5. **Heap Sort:** O(n log n)

**Space Complexity:**
- Main array: O(n)
- Temporary array (for sorting): O(n)
- **Total:** O(n)

---

## Summary Comparison Table

| Program | Data Structure | Best Use Case | Time (Insert) | Time (Search) | Time (Delete) | Space |
|---------|---------------|---------------|---------------|---------------|---------------|-------|
| 01(list) | Graph (Adj List) | Sparse graphs | O(1) | O(E) | - | O(V+E) |
| 01(matrix) | Graph (Adj Matrix) | Dense graphs | O(1) | O(1) | - | O(V²) |
| 02(bst) | BST | Ordered data | O(log n) avg | O(log n) avg | - | O(n) |
| 03(expression) | Binary Tree | Expression eval | O(n) | - | - | O(n) |
| 04(avl) | AVL Tree | Balanced search | O(log n) | O(log n) | O(log n) | O(n) |
| 05(fractional) | Array + Greedy | Optimization | O(n log n) | - | - | O(n) |
| 06(branch) | State Space Tree | Exact solution | O(2ⁿ) | - | - | O(2ⁿ) |
| 06(dp) | DP Table | Optimization | O(n×W) | - | - | O(n×W) |
| 07(heap) | Max Heap | Priority queue | O(log n) | O(1) max | O(log n) | O(n) |

---

## Algorithm Categories

### **Graph Algorithms**
- **Adjacency List:** Space-efficient for sparse graphs
- **Adjacency Matrix:** Fast edge lookup for dense graphs
- **DFS:** Used for path finding, reachability

### **Tree Algorithms**
- **BST:** O(log n) average, O(n) worst case
- **AVL Tree:** Guaranteed O(log n) - self-balancing
- **Expression Trees:** O(n) construction and evaluation

### **Greedy Algorithms**
- **Fractional Knapsack:** O(n log n) - optimal solution

### **Dynamic Programming**
- **0/1 Knapsack:** O(n × W) - pseudo-polynomial, optimal solution

### **Branch and Bound**
- **0/1 Knapsack:** O(2ⁿ) with pruning - exact solution

### **Heap Data Structure**
- **Max Heap:** O(log n) insert/delete, O(1) find max
- **Heap Sort:** O(n log n) - in-place sorting

---

## Key Takeaways

1. **AVL Tree vs BST:** AVL guarantees O(log n) while BST can degrade to O(n)
2. **Adjacency List vs Matrix:** List uses O(V+E) space, Matrix uses O(V²)
3. **Fractional vs 0/1 Knapsack:** 
   - Fractional: O(n log n) greedy solution
   - 0/1 DP: O(n×W) optimal solution
   - 0/1 Branch & Bound: O(2ⁿ) with pruning
4. **Heap Properties:** Fast max/insert/delete but slow min finding
5. **Expression Trees:** Linear time construction from prefix/postfix

---

**Note:** 
- n = number of elements
- V = number of vertices
- E = number of edges  
- W = knapsack capacity
- h = height of tree
- m = number of trees

All complexities are analyzed for worst-case unless specified otherwise.
