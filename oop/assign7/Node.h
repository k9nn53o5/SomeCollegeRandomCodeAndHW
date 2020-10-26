#ifndef NODE_H
#define NODE_H
template <class T>
class Node{
	public:
		Node();
		Node(const T& entry);
		void setdata(T& d);
		void setnext(Node<T>* ptr);
		T getdata()const;
		Node<T>* getnext()const;
	private:
		T data;
		Node<T>* next;

};

template<class T> Node<T>::Node():next(NULL){
}
template<class T> Node<T>::Node(const T& entry):data(entry),next(NULL){
}
template<class T> void Node<T>::setdata(T& d){
		data=d;
}
template<class T> void Node<T>::setnext(Node<T>* ptr){
		next=ptr;
}
template<class T > T Node<T>::getdata()const{
		return data;	
}
template<class T> Node<T>* Node<T>::getnext()const{
		return next;
}
#endif
