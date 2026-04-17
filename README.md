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
 ~ OUTPUT

 <img width="304" height="179" alt="Screenshot 2026-04-17 123202" src="https://github.com/user-attachments/assets/75a8755a-9cf1-4593-91e5-60d106891bdd" />
<img width="314" height="228" alt="Screenshot 2026-04-17 123651" src="https://github.com/user-attachments/assets/64d88e56-56f5-48bc-8d60-5c9f21fd5b88" />
<img width="324" height="198" alt="Screenshot 2026-04-17 123710" src="https://github.com/user-attachments/assets/88c8e255-8d2c-4772-b414-1d0cf787287b" />
<img width="490" height="254" alt="Screenshot 2026-04-17 123738" src="https://github.com/user-attachments/assets/7501139a-a633-4447-a034-41b1ae2368d4" />
<img width="333" height="229" alt="Screenshot 2026-04-17 123757" src="https://github.com/user-attachments/assets/c7d3a992-d2ba-4c23-8344-fa806f96ef0b" />
<img width="437" height="251" alt="Screenshot 2026-04-17 123816" src="https://github.com/user-attachments/assets/ccee4b81-e6c3-4601-833c-70efb0b09dee" />

