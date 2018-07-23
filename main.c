#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512
#define STACK_SIZE 256

static char* ptr;

typedef struct _Stack{
  int size;
  int top;
  char** array;
} Stack;

static Stack* new_stack(){
  Stack* s = malloc(sizeof(Stack));
  s->top = 0;
  s->array = malloc(sizeof(char*) * STACK_SIZE);
  return s;
} 

static void delete_stack(Stack* stack){
  free(stack->array);
  free(stack);
}

static void push(Stack* stack, char* ptr){

  if(stack->top == STACK_SIZE){
    fprintf(stderr, "Stack overflow.");
    exit(1);
  }

  stack->array[stack->top] = ptr;
  stack->top++;
}

static char* pop(Stack* stack){
  if(stack->top == 0){
    fprintf(stderr, "Stack has no item.");
    exit(1);
  }
  
  stack->top--;
  return stack->array[stack->top];
}

static void interpret(char* buf){
  Stack* stack = new_stack();

  while(*buf){
    switch(*buf){

    case '>':
      ptr++;
      break;

    case '<':
      ptr--;
      break;

    case '+':
      ++(*ptr);
      break;

    case '-':
      --(*ptr);
      break;

    case '.':
      putchar(*ptr);
      break;

    case ',':
      *ptr = getchar();
      break;

    case '[':
      if(*ptr == 0)
        while(*buf != ']')
          buf++;
      else
        push(stack, buf);
      break;
      
    case ']':
      buf = pop(stack);
      buf--;
      break;
    }
    
    buf++;
  }

  delete_stack(stack);
}


int main(int argc, char** argv){

  if(argc != 2) {
    fprintf(stderr, "only one arg(filename) to execute. %s\n", *argv);
  }

  FILE* fp;
  char buf[BUF_SIZE];
  
  if((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open %s\n", *argv);
    exit(1);
  }

  fread(buf, sizeof(buf), 1, fp);
  ptr = (char*)malloc(sizeof(char) * BUF_SIZE);
  interpret(buf);
  
  return 0;
}
