
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

//--------------- Patient Object ---------------//

struct Patient
{
	string name;
	int waitingTime;
	string lifeThreatening;

	// comparators to define a priority of a patient in the queue
	bool operator<(Patient compared)
	{
		if(waitingTime < compared.waitingTime)
			return true;
		else
			return false;
	}
	bool operator>(Patient compared)
	{
		if(waitingTime > compared.waitingTime)
			return true;
		else
			return false;
	}
};

//--------------- A way to define Time ---------------//

class Time
{
private:
	int hour;
	int minTen;
	int minOne;
public:
	Time();
	string get();
	void set(int hour, int min);
	void increment();
};
Time::Time()
{
	hour = 12;
	minTen = 0;
	minOne = 0;
}
string Time::get()
{
	return to_string(hour) + ":" + to_string(minTen) + to_string(minOne);
}
void Time::set(int hourInput, int min)
{
	hour = hourInput;
	if(min < 10)
	{
		minTen = 0;
		minOne = min;
	}
	else
	{
		minTen = min/10;
		minOne = min%10;
	}
}
void Time::increment()
{
	minOne++;

	if(minOne == 10)
	{
		minOne = 0;
		minTen++;
		if(minTen == 6)
		{
			minTen = 0;
			hour++;
			if(hour == 13)
				hour = 1;
		}
	}
}

//--------------- For STL priority_queue --------------//

//inform STL priority_queue how to compare Patient objects
class ComparePatient
{
public:
	bool operator()(Patient & p1, Patient & p2)
	{
	   if (p1.waitingTime < p2.waitingTime)
		   return true;
	   return false;
	}
};
// print function for STL priority_queue
template <class T>
void print_queue(T q)
{
	cout << endl << left << setw(17) <<"Name" << " | " << "Waiting Time\n"
			"---------------------------------\n";
    while(!q.empty())
    {
        cout << setw(17) << q.top().name << " | " << q.top().waitingTime << endl;
        q.pop();
    }
    cout << '\n';
}

//--------------- Developed Priority Queue --------------//

class priorityQueue
{
public:
	priorityQueue();
	void push(Patient);
	void pop();
	Patient top();
	int getSize();
	bool isEmpty();

	void swap(int, int);

	void heapUp(int index);
	void heapDown(int index);

	void print();

private:
	vector<Patient> vect;
	Patient emptyFirst;
	int size;

};

priorityQueue::priorityQueue()
{
	// The index 0 will remain an empty
	// From index 1, patients will be added in
	emptyFirst.name = "NOBODY";
	emptyFirst.waitingTime = 100;
	emptyFirst.lifeThreatening = "";

	vect.push_back(emptyFirst);
	size = 0;
}
void priorityQueue::push(Patient newPatient)
{
	vect.push_back(newPatient);
	heapUp(vect.size()-1);
	size++;
}
void priorityQueue::pop()
{
	swap(1, size);
	vect.pop_back();
	heapDown(1);
	size--;
}
Patient priorityQueue::top()
{
	return vect[1];
}
int priorityQueue::getSize()
{
	return size;
}
bool priorityQueue::isEmpty()
{
	return size == 0;
}

void priorityQueue::heapUp(int index)
{
	int parentIndex = index/2;
	if(vect[parentIndex] < vect[index])
	{
		swap(parentIndex, index);
		heapUp(parentIndex);
	}
}
void priorityQueue::heapDown(int index)
{
	int left  = 2 * index;
	int right = 2 * index + 1;
	int largest = index;

	if(left < size && vect[left] > vect[index] )
		largest = left;
	if(right < size && vect[right] > vect[largest])
		largest = right;

	if(largest != index)
	{
		swap(index, largest);
		heapDown(largest);
	}
}

void priorityQueue::swap(int parent, int child)
{
	Patient temp = vect[parent];
	vect[parent] = vect[child];
	vect[child] = temp;
}
void priorityQueue::print()
{
	cout << endl << left << setw(17) <<"Name" << " | " << "Waiting Time\n"
			"---------------------------------\n";
	for(int i = 1; i <= size; i++)
	{
		cout << setw(17) << vect[i].name << " | " << vect[i].waitingTime << endl;
	}
}

//-------------- Additional Helper Functions --------------//

// At every passing minute, checks whether it is time for life-threatening
// interruption. If so, life-threatening patients will be treated at
// that moment and delay the rest of the patients 25 minutes.
template <class priorityQueueTemplate>
void checkLifeThreatening(priorityQueueTemplate & emergencyQueue,
		Time & clockTime, vector<Patient> & lifeThreateningPatients)
{
	// traverse through array of life-threatening patients
	for(int i= 0; i < lifeThreateningPatients.size(); i++)
	{
		// if the current time matches the patient's interruption time..
		if (clockTime.get() == lifeThreateningPatients[i].lifeThreatening)
		{
			cout << "\n*********************************"
					"\n** Life Threatening!!";

			// push the patient onto the general priority queue
			// (will be put to the top, as highest priority)
			emergencyQueue.push(lifeThreateningPatients[i]);

			cout << "\n** Current Patient: " << emergencyQueue.top().name;
			cout << "\n** Start Time: " << clockTime.get();

			// delay 25 minutes
			for(int i = 0; i < 25; i++)
				clockTime.increment();

			// remove patient from both lists
			emergencyQueue.pop();
			lifeThreateningPatients.erase(lifeThreateningPatients.begin());

			cout << "\n** End Time: " << clockTime.get() <<
					"\n*********************************\n\n";
		}
	}
}

#endif /* HEADER_H_ */
