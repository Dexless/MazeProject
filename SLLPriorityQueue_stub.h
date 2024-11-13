/*************************************************************************************
*                                                                                    *
* A priority queue is a special variation of a queue. Rather than returning the fisrt*
* value inserted, it returns the highest priority value. To do this, data must be    *
* stored in pairs. For every value of any type you insert, you must also give it a   *
* numerical priority. The data structure can then be set up to always return the     *
* highest value priority, or the lowest. For finding the shortest path, you will want*
* to always return the lowest value priority.                                        *
* NOTE: Priority Queues are normally created using heaps. Since you have not studied * 
* heaps, we will use a SLL instead.                                                  *
* To make a normal SLL based queue into a priority queue you just need to adjust the *
* append function to search for the appropriate location (ascending order) before    *
* inserting.                                                                         *
*                                                                                    *
*************************************************************************************/

struct Node 
{
    int distance;  // The priority (distance in this case)
    int cellIndex; // Value to be stored (cell index in this case)
    Node* next;    // Pointer to the next node

    // Constructor for a new node
    Node(int dist, int index) 
	{
		distance = dist; 
		cellIndex = index; 
		next = nullptr;
	}
};

class SLLPriorityQueue 
{
private:
    Node* head;  // Pointer to the first node

public:
    // Constructor to initialize an empty priority queue
    SLLPriorityQueue() 
    {
        head = nullptr;    
    }

    // Destructor to clean up memory
    ~SLLPriorityQueue() 
    {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a new node with the given distance and cellIndex
    void enqueue(int distance, int cellIndex) 
    {
        Node* newNode = new Node(distance, cellIndex);

        // If the list is empty or the new node has a higher priority (smaller distance)
        if () 
        {
			// Insert the newNode before the head using 2 assignments
            // Assignment 1
            // Assignment 2
        }
        else 
        {
            Node* current = head;
            // Traverse the list to find the location where the next node's distance
            // is greater than to the given distance or their is no next object
            while () 
            {
                current = current->next;
            }

            // Insert the newNode after current using 2 assignments
            // Assignment 1
            // Assignment 2
        }
    }

    // Dequeue (remove and return) the node with the highest priority (smallest distance)
    Node dequeue() 
    {
        if (head == nullptr) 
        {
            throw std::runtime_error("Priority queue is empty!");
        }

        // Remove the head node (smallest distance)
        Node* temp = head;
        Node dequeuedNode = *head;  // Copy the node's data
        head = head->next;
        delete temp;  // Delete the old head
        return dequeuedNode;  // Return the data of the dequeued node
    }

    // Peek at the node with the highest priority without removing it
    Node peek() const 
    {
        if (head == nullptr) 
        {
            throw std::runtime_error("Priority queue is empty!");
        }

        // The head contains the smallest distance
        return *head;
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return head == nullptr;
    }
};
