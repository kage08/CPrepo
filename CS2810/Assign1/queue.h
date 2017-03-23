//Structure to store the information of student.
//next points to next student in queue

typedef struct student_{
	int id;
	struct student_* next;
}student;

//Creates a new student structure with given id and returns th e pointer to it
student* new_student(int);

//Structure of queue data structure
typedef struct queue_{
	student* front;
	student* rear;
	int size;
}queue;

//Creates a new empty queue structure and returns pointer to it 
queue* new_queue();

//enqueues the student structure to the queue
void enqueue(queue*,student*);

//dequeues the student structure at end of queue if non-empty and returs pointer to it. If empty it returs NULL.
student* dequeue(queue*);

//returns the id of the student at top of queue
int top(queue*);

//returns the id of the student at bottom of queue
int bottom(queue*);

//checks if queue is empty and returns 1 if true and 0 if false
int is_empty(queue*);

//returns no. of students ingiven queue
int get_size(queue*);

//merges the subqueue with main queue
void merge_queues(queue*,queue*);
//prints the queue in line
void print_queue(queue*);

//inputs students into queue form string output
void input_queue(queue*,char*);

//returns the no. of students in the subqueue not in main queue
int size_subqueue(queue*,queue*);
//sorts the array of N-1 queues on size of sub queue
void sort_queue_order(int*,queue**,int);
