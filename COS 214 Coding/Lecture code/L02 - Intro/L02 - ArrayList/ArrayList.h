#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <string>

  class ArrayList {
		
	  public:
			ArrayList();
			ArrayList(int);
			bool insertElement(int);
			void sort();
			bool isFull();
			bool isEmpty();
			void print();
			virtual ~ArrayList();
		protected:
			//only super class can access, not main
			virtual bool directionOperator(int,int) = 0;
			virtual std::string getName() = 0;
		private:
			int size;
			int current;
			int* storage;
	};


  class AscendingArrayList : public ArrayList {
		public:
			AscendingArrayList();
			AscendingArrayList(int);
			virtual std::string getName(); 
		protected:
			virtual bool directionOperator(int,int);
		
	};

	class DescendingArrayList : public ArrayList {
		public:
			DescendingArrayList();
			DescendingArrayList(int);
			virtual std::string getName();
		protected:
			virtual bool directionOperator(int,int);
	};

#endif
