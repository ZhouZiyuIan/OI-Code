import sys
import threading

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    n, m = map(int, sys.stdin.readline().split())
    expr = sys.stdin.readline().split()
    b = list(map(int, sys.stdin.readline().split()))
    queries = [tuple(map(int, sys.stdin.readline().split())) for _ in range(m)]

    # Step 1: Parse the postfix expression into a tree
    # Each node: (is_leaf, value, left, right, b)
    # We also need to know for each leaf its position in the original numbers
    class Node:
        def __init__(self, idx):
            self.idx = idx  # node index in nodes[]
            self.left = None
            self.right = None
            self.b = None
            self.is_leaf = False
            self.value = 0
            self.leaf_id = -1  # if is_leaf, which number it is (0-based)
            self.parent = None

    nodes = []
    stack = []
    b_ptr = 0
    leaf_id = 0
    leaf_nodes = []
    for token in expr:
        if token == '*':
            right = stack.pop()
            left = stack.pop()
            node = Node(len(nodes))
            node.left = left
            node.right = right
            node.b = b[b_ptr]
            b_ptr += 1
            left.parent = node
            right.parent = node
            nodes.append(node)
            stack.append(node)
        else:
            node = Node(len(nodes))
            node.is_leaf = True
            node.value = int(token)
            node.leaf_id = leaf_id
            leaf_nodes.append(node)
            leaf_id += 1
            nodes.append(node)
            stack.append(node)
    root = stack[0]

    # Step 2: For each node, compute its value
    def dfs(node):
        if node.is_leaf:
            return node.value
        lv = dfs(node.left)
        rv = dfs(node.right)
        node.value = (lv + rv) * node.b
        return node.value
    dfs(root)

    # Step 3: For each leaf, record the path to root and the effect of changing it
    # We can precompute for each leaf a "multiplier" that tells how much changing this leaf by +1 changes the root value
    # This is similar to computing the derivative of the expression with respect to each leaf

    # For each node, we can compute the "multiplier" from this node to root
    # For root, multiplier is 1
    # For each child, multiplier = parent's multiplier * parent's b
    # But, when going up, if node is left child, the sum is (left + right) * b, so changing left by +1 increases parent by b
    # Similarly for right child

    # So, for each node, we can compute its "multiplier to root"
    multiplier = [0] * len(nodes)
    multiplier[root.idx] = 1

    def dfs2(node):
        if node.is_leaf:
            return
        # left child: changing left by +1 increases node.value by node.b
        multiplier[node.left.idx] = multiplier[node.idx] * node.b
        # right child: same
        multiplier[node.right.idx] = multiplier[node.idx] * node.b
        dfs2(node.left)
        dfs2(node.right)
    dfs2(root)

    # For each leaf, record its node and multiplier
    leaf_to_node = [None] * n
    leaf_to_mult = [0] * n
    for node in leaf_nodes:
        leaf_to_node[node.leaf_id] = node
        leaf_to_mult[node.leaf_id] = multiplier[node.idx]

    # Step 4: For each query, update the value and propagate up
    # Since each update only changes one leaf, and we can compute the delta to root directly
    # So, we can keep the current value of each leaf, and the root value
    leaf_values = [node.value for node in leaf_nodes]
    root_value = root.value

    for x, y in queries:
        x -= 1
        old = leaf_values[x]
        delta = y - old
        root_value += delta * leaf_to_mult[x]
        leaf_values[x] = y
        print(root_value)

threading.Thread(target=main).start()