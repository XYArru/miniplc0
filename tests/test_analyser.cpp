#include "catch2/catch.hpp"

#include "instruction/instruction.h"
#include "tokenizer/tokenizer.h"
#include "analyser/analyser.h"

/*
	不要忘记写测试用例喔。
*/

TEST_CASE("AT - Easy Test") {
	
		/*std::string input =
		"begin\n"
		"	const b = 1;\n"
		"	var a = 1;\n"
		"	print(a+b);\n"
		"end\n";*/
	
	std::vector<miniplc0::Token> input = {
		miniplc0::Token(miniplc0::TokenType::BEGIN,std::string("begin"),std::make_pair(0,0),std::make_pair(0,5)),
		miniplc0::Token(miniplc0::TokenType::CONST,std::string("const"),std::make_pair(2,1),std::make_pair(2,6)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,'b',std::make_pair(2,7),std::make_pair(2,8)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(2,9),std::make_pair(2,10)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER ,1,std::make_pair(2,11),std::make_pair(2,12)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(1,10),std::make_pair(1,11)),
		miniplc0::Token(miniplc0::TokenType::VAR,std::string("var"),std::make_pair(1,1),std::make_pair(1,4)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(1,5),std::make_pair(1,6)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(1,7),std::make_pair(1,8)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,1,std::make_pair(1,9),std::make_pair(1,10)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(1,10),std::make_pair(1,11)),
		miniplc0::Token(miniplc0::TokenType::PRINT ,std::string("print"),std::make_pair(3,1),std::make_pair(3,6)),
		miniplc0::Token(miniplc0::TokenType::LEFT_BRACKET ,'(',std::make_pair(3,6),std::make_pair(3,7)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(3,7),std::make_pair(3,8)),
		miniplc0::Token(miniplc0::TokenType::PLUS_SIGN,'+',std::make_pair(3,8),std::make_pair(3,9)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,'b',std::make_pair(3,9),std::make_pair(3,10)),
		miniplc0::Token(miniplc0::TokenType::RIGHT_BRACKET ,')',std::make_pair(3,10),std::make_pair(3,11)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(3,11),std::make_pair(3,12)),
		miniplc0::Token(miniplc0::TokenType::END,std::string("end"),std::make_pair(4,0),std::make_pair(4,3)),
	};
	std::vector<miniplc0::Instruction> output = {
		miniplc0::Instruction(miniplc0::Operation::LIT,1),
		miniplc0::Instruction(miniplc0::Operation::LIT,1),
		miniplc0::Instruction(miniplc0::Operation::LOD,1),
		miniplc0::Instruction(miniplc0::Operation::LOD,0),
		miniplc0::Instruction(miniplc0::Operation::ADD,0),
		miniplc0::Instruction(miniplc0::Operation::WRT,0)
	};
	miniplc0::Analyser az(input);
	auto result = az.Analyse();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
}

TEST_CASE("AT - AssignmentStatement Test 1") {
	/*
		std::string input =
		"begin\n"
		"	var a = 1;\n"
		"	a = 2;\n"
		"end\n";*/
	
	std::vector<miniplc0::Token> input = {
		miniplc0::Token(miniplc0::TokenType::BEGIN,std::string("begin"),std::make_pair(0,0),std::make_pair(0,5)),

		miniplc0::Token(miniplc0::TokenType::VAR,std::string("var"),std::make_pair(1,1),std::make_pair(1,4)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(1,5),std::make_pair(1,6)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(1,7),std::make_pair(1,8)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,1,std::make_pair(1,9),std::make_pair(1,10)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(1,10),std::make_pair(1,11)),

		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(2,1),std::make_pair(2,2)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(2,3),std::make_pair(2,4)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,2,std::make_pair(2,5),std::make_pair(2,6)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(2,6),std::make_pair(2,7)),

		miniplc0::Token(miniplc0::TokenType::END,std::string("end"),std::make_pair(4,0),std::make_pair(4,3)),
	};
	std::vector<miniplc0::Instruction> output = {
		miniplc0::Instruction(miniplc0::Operation::LIT,1),
		miniplc0::Instruction(miniplc0::Operation::LIT,2),
		miniplc0::Instruction(miniplc0::Operation::STO,0),
	};
	miniplc0::Analyser az(input);
	auto result = az.Analyse();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
}