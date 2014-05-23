#include <iostream>

//#include "linkedlist.h"
//#include "stringstuff.h"
//#include "MyString.h"

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main() {

    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	 CppUnit::TextUi::TestRunner runner;
    runner.addTest( registry.makeTest() );
	 
	// Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
    bool wasSuccessful = runner.run();
    //bool wasSuccessful = runner.run( "", false );
    return wasSuccessful ? 0 : 100;
}
