simpletest: simpletest.cpp
	c++ -Wall -std=c++20 simpletest.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_unit_test_framework -o simpletest

closestsum_dp: closestsum_dp.cpp
	c++ -Wall -std=c++20 closestsum_dp.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_unit_test_framework -o closestsum_dp

closestsum_simple: closestsum_simple.cpp
	c++ -Wall -std=c++20 closestsum_simple.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_unit_test_framework -o closestsum_simple

customer: customer.cpp
	c++ -Wall -std=c++20 customer.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_unit_test_framework -o customer

clean:
	test ! -f simpletest || rm simpletest
	test ! -f closestsum_dp || rm closestsum_dp
	test ! -f closestsum_simple || rm closestsum_simple