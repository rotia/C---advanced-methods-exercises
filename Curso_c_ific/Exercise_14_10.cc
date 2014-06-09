int main(){
	Vectorish target(100,1000);
	Vectorish source(200,2000);
	Vectorish target2(std::move(source));
}

Vectorish(Vectorish&& other):data(ALLOCATE(0)),size(0) {
	SWAP(other);
}

Vectorish& operator=(Vectorish&& other) {
	this->SWAP(other);
	return *this;
}

void SWAP(const Vectorish& other){
	std::swap(this->data, other.data);
	std::swap(this->size, other.size); 
}
