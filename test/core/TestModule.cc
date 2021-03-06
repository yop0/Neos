#include "../../include/core/all.hxx"
#include "../../include/meta/all.hxx"
#include "../../include/test/all.hxx"

class TestModule : public TestAtom
{
public:
	virtual bool runTests() override
	{
		TEST_ASSERT(is_module<>::value == false); 
		TEST_ASSERT(is_module<int>::value == false); 
		TEST_ASSERT(is_module<Atom<>>::value == true); 
		TEST_ASSERT(is_module<Module>::value == true); 
		TEST_ASSERT( (is_module<Module, Module, int, Module>::value == false) );
		TEST_ASSERT( (is_module<Module, Module, Module>::value == true) ); 
		TEST_ASSERT( (is_module<Module, Atom<>, Atom<>>::value == true) ); 
	}
};

int main() 
{
	TestModule tm; 
	tm.runTests(); 
}
