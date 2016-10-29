#include <cstdio>
const int MAXN = 2000;

char Queue[MAXN];
char Stack[MAXN];
int QueueCnt, StackCnt;
bool isBalanced = true;
bool isLacking = false; // lacking operand
bool isRemain = false;  // remain operand

// configuration
bool isOperator(char op) {
  switch (op) {
  case '!':
  case '&':
  case '|':
    return true;
  default:
    return false;
  }
}

int precedence(char op) {
  switch (op) {
  case '!':
    return 3;
  case '&':
    return 2;
  case '|':
    return 1;
  }
}

int associative(char op) {
  switch (op) {
  case '&':
  case '|':
    return 0;
  case '!':
    return 1;
  }
}

int operands(char op) {
  switch (op) {
  case '&':
  case '|':
    return 2;
  case '!':
    return 1;
  }
}

void apply(char op) {
  if (StackCnt < operands(op)) {
    isLacking = true;
    return;
  }
  switch (op) {
  case '&':
    Stack[StackCnt - 2] &= Stack[StackCnt - 1];
    StackCnt--;
    return;
  case '|':
    Stack[StackCnt - 2] |= Stack[StackCnt - 1];
    StackCnt--;
    return;
  case '!':
    Stack[StackCnt - 1] = !Stack[StackCnt - 1];
    return;
  }
}

int main() {
  int kase = 0;
  char ch;
  bool isEmptyLine = true;
  while ((ch = getchar()) != EOF) {
    if (ch == ' ') {
      continue;
    }
    if (ch == '\n') {
      if (isEmptyLine) {
        continue;
      }
      while (StackCnt) {
        Queue[QueueCnt++] = Stack[--StackCnt];
      }
      // PostFix
      for (int i = 0; i < QueueCnt; i++) {
        char op = Queue[i];
        if (isOperator(op)) {
          apply(op);
        } else {
          if (op == 'V' || op == 'T') {
            Stack[StackCnt++] = 1;
          } else if (op == 'F') {
            Stack[StackCnt++] = 0;
          } else if (op == '(') {
            isBalanced = false;
          } else {
            // uncatched characters
          }
        }
      }
      if (StackCnt > 1) {
        isRemain = true;
      }
      printf("Expression %d: ", ++kase);
      if (!isBalanced) {
        puts("Unbalanced parenthesis ");
      } else if (isLacking) {
        puts("Lacking operand");
      } else if (isRemain) {
        puts("Remain operand");
      } else {
        puts(Stack[StackCnt - 1] ? "V" : "F");
      }
      // Ending
      fflush(stdout);
      isBalanced = isEmptyLine = true;
      isLacking = isRemain = false;
      QueueCnt = 0;
      continue;
    }
    isEmptyLine = false;
    if (ch == '(') {
      Stack[StackCnt++] = ch;
    } else if (ch == ')') {
      isBalanced = false;
      while (StackCnt) {
        if (Stack[StackCnt - 1] == '(') {
          isBalanced = true;
          StackCnt--;
          break;
        }
        Queue[QueueCnt++] = Stack[--StackCnt];
      }
    } else if (isOperator(ch)) {
      int a = associative(ch), p = precedence(ch);
      while (StackCnt) {
        char op = Stack[StackCnt - 1];
        if (isOperator(op) &&
            (a == 0 && p <= precedence(op) || a == 1 && p < precedence(op))) {
          Queue[QueueCnt++] = Stack[--StackCnt];
        } else {
          break;
        }
      }
      Stack[StackCnt++] = ch;
    } else {
      Queue[QueueCnt++] = ch;
    }
  }
  return 0;
}
