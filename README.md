
🚀 Message Thread Tree CRUD System


A High-Performance Hierarchical Chat Simulation Engine in C

📌 Overview


The Message Thread Tree CRUD System is a high-performance, console-based chat simulation engine designed using C programming language and the Left-Child Right-Sibling (LCRS) Tree Data Structure.


It replicates the core architecture of modern messaging platforms such as:


Reddit (threaded comments)

Discord (nested replies)

Slack (conversation chains)


This system demonstrates how scalable hierarchical communication models can be implemented using efficient memory-managed tree structures.


🎯 Key Highlights

⚡ Dynamic hierarchical thread management

🌳 General Tree using LCRS representation

🔁 Recursive DFS-based traversal system


🧠 Fully dynamic memory allocation (no fixed limits)


🧩 Modular CRUD architecture

💬 Real-world chat thread simulation model


👨‍💻 Developers

N. Mithra Srikhar

E. Vineeth Reddy

🧠 System Architecture


🔷 Data Structure Model (LCRS Tree)


Each message node is represented as:


typedef struct MessageNode {

int id;
    
 char text[256];
    
 struct MessageNode *firstChild;
 
   
 struct MessageNode *nextSibling;
 
}
MessageNode;

📌 Design Logic


firstChild → First reply in a thread

nextSibling → Next message at same hierarchy level

Enables infinite branching without arrays

⚙️ Core Features


🔹 1. Create (Insert Message / Reply)

Searches parent node using DFS

Inserts node as:

First child (if no replies exist)

Else appended as sibling

🔹 2. Read (Search + Display)

🔍 Search

Recursive DFS traversal

Returns node by unique ID

📊 Display Engine

Pre-order traversal

Indentation-based visualization

🔹 3. Update (Modify Message)

Locates node via ID

Safely updates message content

🔹 4. Delete (Subtree Removal)

Deletes selected node

Recursively removes all child replies

Ensures memory cleanup using DFS

🔄 Algorithm Workflow

User Input → Operation Selection → Tree Traversal (DFS)

→ Node Processing → Memory Update → Output Rendering

🖥 System Output Visualization

ROOT THREAD [0]

│

├── Message [1]: System Design Discussion

│     └── Reply [3]: Use tree structure for scalability

│

└── Message [2]: Documentation Plan

🛠 Technology Stack

Component   	Technology

Language	C


Data Structure	General Tree (LCRS)

Algorithm	DFS (Recursive Traversal)

Memory Model	Dynamic Allocation (malloc/free)

📂 Project Structure

message-thread-tree/


│


├── main.c 
                 # Core implementation (CRUD engine)

├── README.md  
                 # Project documentation


├── docs/ 
                 # Architecture diagrams (optional)


└── screenshots/  
                  # Output visuals
                  

🚀 Getting Started

🔧 Requirements

GCC Compiler or any C compiler

Linux / Windows / macOS

⚡ Build & Run

# Clone repository

git clone https://github.com/yourusername/message-thread-tree.git


# Navigate project directory

cd message-thread-tree


# Compile source code

gcc main.c -o message_tree


# Execute program

./message_tree

📊 Performance Analysis

Operation	  Complexity

Insert	O(n)

Search	O(n)

Delete	O(n)

Display	O(n)

🔐 Advantages


✔ Scalable thread-based architecture

✔ Efficient memory utilization (no static arrays)

✔ Real-world chat model simulation

✔ Fully recursive structure

✔ Easy extensibility


⚠️ Limitations

Console-based interface (no GUI)

No persistent database storage

Single-session runtime system

🔮 Future Scope

🌐 Real-time networking support (multi-user chat system)

💾 Database integration (MySQL / MongoDB)

🖥 Web-based UI (React / HTML5)

🔐 Encryption layer (secure messaging)

📱 Mobile application version

📚 Learning Outcomes


This project strengthens understanding of:


Tree data structures (LCRS model)

Recursive algorithm design

Memory management in C

System-level programming concepts

Real-world chat system architecture  

DEMO OUTPUT: 


<img width="314" height="228" alt="Screenshot 2026-04-17 123651" src="https://github.com/user-attachments/assets/651a5477-a03f-430e-9c79-f5ea0ef81fad" />




<img width="324" height="198" alt="Screenshot 2026-04-17 123710" src="https://github.com/user-attachments/assets/62a62b57-270a-417a-81ae-4ccdb0c285a2" />



<img width="490" height="254" alt="Screenshot 2026-04-17 123738" src="https://github.com/user-attachments/assets/faadc5da-4cf5-4404-8ad0-851204f948ab" />




<img width="333" height="229" alt="Screenshot 2026-04-17 123757" src="https://github.com/user-attachments/assets/36dadd61-1cc0-4328-b3ff-2cad94c87366" />


<img width="437" height="251" alt="Screenshot 2026-04-17 123816" src="https://github.com/user-attachments/assets/63099b23-bcf9-4a33-9972-c5b27cb7ed09" />




   

🏁 Conclusion


The Message Thread Tree CRUD System successfully demonstrates how hierarchical chat systems can be implemented efficiently using advanced tree data structures. It serves as a strong foundation for building scalable messaging platforms and distributed communication systems.

⭐ Repository Status


🔥 Educational Project | System Design Focus | Data Structures Implementation
