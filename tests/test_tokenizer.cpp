#include "catch2/catch.hpp"
#include "tokenizer/tokenizer.h"
#include "fmt/core.h"

#include <sstream>
#include <vector>

// 下面是示例如何书写测试用例
/*
TEST_CASE("Test hello world.") {
	
	std::string input =
		"begin\n";
		"	var a = 1;\n"
		"	const b = 1\n"
		"	print(a+b);\n"
		"end\n";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
	
}*/
TEST_CASE("Full Test") {
	std::string input =
		"begin\n"
		"	var a = 1;\n"
		"	const b = 1\n"
		"	print(a+b);\n"
		"end\n";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {
		miniplc0::Token(miniplc0::TokenType::BEGIN,std::string("begin"),std::make_pair(0,0),std::make_pair(0,5)),
		miniplc0::Token(miniplc0::TokenType::VAR,std::string("var"),std::make_pair(1,1),std::make_pair(1,4)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(1,5),std::make_pair(1,6)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(1,7),std::make_pair(1,8)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,1,std::make_pair(1,9),std::make_pair(1,10)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(1,10),std::make_pair(1,11)),
		miniplc0::Token(miniplc0::TokenType::CONST,std::string("const"),std::make_pair(2,1),std::make_pair(2,6)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,'b',std::make_pair(2,7),std::make_pair(2,8)),
		miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',std::make_pair(2,9),std::make_pair(2,10)),
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER ,1,std::make_pair(2,11),std::make_pair(2,12)),
		miniplc0::Token(miniplc0::TokenType::PRINT ,std::string("print"),std::make_pair(3,1),std::make_pair(3,6)),
		miniplc0::Token(miniplc0::TokenType::LEFT_BRACKET ,'(',std::make_pair(3,6),std::make_pair(3,7)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),std::make_pair(3,7),std::make_pair(3,8)),
		miniplc0::Token(miniplc0::TokenType::PLUS_SIGN,'+',std::make_pair(3,8),std::make_pair(3,9)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,'b',std::make_pair(3,9),std::make_pair(3,10)),
		miniplc0::Token(miniplc0::TokenType::RIGHT_BRACKET ,')',std::make_pair(3,10),std::make_pair(3,11)),
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(3,11),std::make_pair(3,12)),
		miniplc0::Token(miniplc0::TokenType::END,std::string("end"),std::make_pair(4,0),std::make_pair(4,3)),
	};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}

	//std::pair<std::vector<Token>, std::optional<CompilationError>> AllTokens();
	
	
	REQUIRE((result.first == output));
}


TEST_CASE("StringStream Test") {

	std::string input =
		"test  string";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("test"),std::make_pair(0,0),std::make_pair(0,4)),
		miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("string"),std::make_pair(0,6),std::make_pair(0,12))
	};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
}

TEST_CASE("Number Test") {

	std::string input =
		"0123";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {
		miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,123,std::make_pair(0,0),std::make_pair(0,4)),
	};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
}

TEST_CASE("SEMICOLON Test") {

	std::string input =
		";";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {
		miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',std::make_pair(0,0),std::make_pair(0,1))
	};
	auto result = tkz.AllTokens();
	if (result.second.has_value()) {
		FAIL();
	}
	REQUIRE((result.first == output));
}