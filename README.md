Message Thread Tree CRUD

A real-time chat thread simulation implemented in C using a General Tree (Left-Child Right-Sibling) data structure. This application demonstrates hierarchical data management, recursive algorithms, and dynamic memory handling.

@ Team Members

1.N.Mithra Srikhar

2.E. Vineeth Reddy

#Problem Statement

In modern communication platforms (like Reddit, Slack, or Discord), messages are organized in threads. A single message can have multiple replies, and those replies can have their own replies.

The Challenge: Efficiently represent a hierarchical, multi-level conversation where each node can have an infinite number of children (replies) without using a fixed-size array or wasting memory.

🛠 Data Structure Used

This project utilizes a General Tree implemented via the Left-Child, Right-Sibling (LCRS) representation.

Structure Definition:

id: A unique integer to identify the message.


text: A character array (string) containing the message content.


*firstChild: Pointer to the first reply (child) of the message.


*nextSibling: Pointer to the next message (sibling) at the same indentation level.


#Algorithm Explanation

1. Create (Add Node)
   
The program searches for the parentId using a recursive depth-first search.

If the parent has no firstChild, the new node is assigned there.

If a firstChild exists, the program traverses the nextSibling pointers until it reaches the end of the list and appends the new node.

2. Read (Search & Display)
   
Search: A recursive function visits every node until the ID matches.

Display: Uses a recursive Pre-order traversal. A depth variable is passed through each call to print leading spaces, creating a visual "tree" effect.

3. Update
   
Locates the node by ID and uses strncpy to safely overwrite the existing message buffer.

4. Delete
   
When a node is deleted, the algorithm ensures no memory leaks occur by recursively calling freeTree on the firstChild (deleting the entire sub-thread) before freeing the target node itself.

#Compilation Instructions

To run this project locally, ensure you have a C compiler (like GCC) installed.

1.Clone the repository:

git clone https://github.com/yourusername/message-thread-tree.git
cd message-thread-tree

2.Compile the code:

gcc main.c -o message_tree

3.Run the application:

./message_tree

#Sample Output

 MESSAGE THREAD TREE (CRUD)

 
1. Add Message/Reply (Create)
2. Delete Message (Delete)
...
Selection: 5

 ~CURRENT CHAT FEED
|-- [0] Main Topic: Project Discussion
    |-- [1] I think we should use C for the project.
        |-- [3] Agreed, it's great for memory management!
    |-- [2] What about the documentation?
