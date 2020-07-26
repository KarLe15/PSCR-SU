#include "List.h" //
namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	return len; /// FAUTE : Must return len ; not reccursive call
//	return length(); /// FAUTE : Must return len ; not reccursive call
}



//void Chainon::print (std::ostream & os) { /// Faute : Should be const method corresponding to declaration
void Chainon::print (std::ostream & os) const { //
	os << data ;
	if (next != nullptr) {
		os << ", ";
		next->print(os);
	}
	/// next->print() should be called only if next != nullptr
//	next->print(os);
}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	/// Fautes vérifier si (index < size)

	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

void List::push_front (const std::string& val) {  /// Fautes ::: Multiple implementation of method
	tete = new Chainon(val,tete);
}

//bool empty() {/// Fautes :: Should be in List namespace
bool List::empty() {
	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}

	std::ostream & operator<< (std::ostream & os, const pr::List & vec)
	{
		os << "[";
		if (vec.tete != nullptr) {
			vec.tete->print (os) ;
		}
		os << "]";
		return os;
	}

} // namespace pr





