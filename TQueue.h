template <class T>
class TQueue
{
	T *mas;
	int MaxSize, Head, Tail, count;
public:
	TQueue(int _MaxSize = 10) {
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		Head = 0;
		Tail = -1;
		count = 0;
	}
	TQueue<T> & operator=(const TQoeoe <T> &q)
	{
		if (this != &q) {
			if (MaxSize != q.MaxSize) {
				delete[] mas;
				MaxSize = q.MaxSize;
				mas = new<T>[MaxSize];
			}
			for (int i = 0; i < MaxSize; i++) {
				mas[i] = q.mas[i];
				count = q.count;
				Head = q.Head;
				Tail = q.Tail;
			}
		}
		return *this;
	}
	bool Empty() {
		if (count == 0)
			return true;
		else return false;
	}
	bool Full() {
		if (count > MaxSize)
			return true;
		else return false;
	}
	void Push(T el)
	{
		if (Full())
			throw 1;
		if (Tail != MaxSize - 1)
			Tail++;
		else Tail = 0;
		mas[Tail] = el;
		count++;
	}
	T pop() {
		if (Empty()) throw - 1;
		int OldHead = Head;
		if (Head != MaxSize - 1)
			Head++;
		else
			Head = 0;
		count--;
		return mas[OldHead];
	}
	T front() {
		return mas[Head];
	}
	T back() {
		return mas[Tail];
	}
	int FirstElem() {
		return Head;
	}
	int LastElem() {
		return  Tail;
	}
};
