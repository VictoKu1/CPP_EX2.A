/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and
 * are not complete.
 *
 * AUTHORS: <Victor Kushnir>
 *
 * Date: 2020-02
 */

#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <stdexcept>
using namespace ariel;
#include <string>
using namespace std;

TEST_CASE("Just a test.") {
  Board board;
  CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
  CHECK(board.read(100, 200, Direction::Horizontal, 4) == "abcd");
}
TEST_CASE("Test for a row .") {
  Board board;
  string s = "AbCdE";
  string s1 = "____________AbCdE";
  CHECK_NOTHROW(board.post(14, 15, Direction::Horizontal, s));
  CHECK(board.read(14, 0, Direction::Horizontal, 17) == s1);
}
TEST_CASE("Empty horizontal space test for length in [0,159] .") {
  Board board;
  string s = "";
  for (int i = 1; i <= 159; i++) {
    s.append("_");
    CHECK(board.read(0, 0, Direction::Horizontal, i) == s);
  }
}
TEST_CASE("Empty vertical space test for length in [0,159] .") {
  Board board;
  string s = "";
  for (int i = 1; i <= 159; i++) {
    s.append("_");
    CHECK(board.read(0, 0, Direction::Vertical, i) == s);
  }
}
TEST_CASE("Test for horizontal data correctness.") {
  Board board;
  CHECK_NOTHROW(board.post(14, 15, Direction::Horizontal, "qwerty1"));
  CHECK_NOTHROW(board.post(14, 15, Direction::Horizontal, "asdfgh1"));
  CHECK(board.read(14, 15, Direction::Horizontal, 7) == "asdfgh1");
}
TEST_CASE("Test for vertical data correctness.") {
  Board board;
  CHECK_NOTHROW(board.post(14, 15, Direction::Vertical, "qwerty1"));
  CHECK_NOTHROW(board.post(14, 15, Direction::Vertical, "asdfgh1"));
  CHECK(board.read(14, 15, Direction::Vertical, 7) == "asdfgh1");
}
TEST_CASE("Vertical on horizontal test for overwrite .") {
  Board board;
  CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd1"));
  CHECK_NOTHROW(board.post(99, 202, Direction::Vertical, "xyz"));
  CHECK(board.read(100, 200, Direction::Horizontal, 7) == "abyd1__");
}