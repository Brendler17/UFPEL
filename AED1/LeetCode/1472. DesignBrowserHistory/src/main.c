#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page {
  char* url;
  struct Page* nextPage;
  struct Page* prevPage;
} Page;

typedef struct {
  Page* firstPage;
  Page* lastPage;
  Page* currentPage;
  int numberOfPages;
} BrowserHistory;

BrowserHistory* browserHistoryCreate(char* homepage) {
  BrowserHistory* browserHistory = (BrowserHistory*)malloc(sizeof(BrowserHistory));
  if (browserHistory == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  Page* firstPage = (Page*)malloc(sizeof(Page));
  if (firstPage == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  firstPage->url = (char*)malloc((strlen(homepage) + 1) * sizeof(char));
  if (firstPage->url == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  strcpy(firstPage->url, homepage);
  firstPage->nextPage = NULL;
  firstPage->prevPage = NULL;
  browserHistory->firstPage = firstPage;
  browserHistory->lastPage = firstPage;
  browserHistory->currentPage = firstPage;
  browserHistory->numberOfPages = 1;

  return browserHistory;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
  Page* newPage = (Page*)malloc(sizeof(Page));
  if (newPage == NULL) {
    printf("\nError allocating memory!\n");
    return;
  }

  if (obj->currentPage != obj->lastPage) {
    Page* lostPage = obj->currentPage->nextPage;

    while (lostPage != NULL) {
      Page* auxPage = lostPage;
      lostPage = lostPage->nextPage;
      free(auxPage);
      obj->numberOfPages--;
    }

    obj->lastPage = obj->currentPage;
  }

  newPage->url = (char*)malloc((strlen(url) + 1) * sizeof(char));
  if (newPage->url == NULL) {
    printf("\nError allocating memory!\n");
    return;
  }

  strcpy(newPage->url, url);
  newPage->nextPage = NULL;
  newPage->prevPage = obj->lastPage;
  obj->lastPage->nextPage = newPage;
  obj->lastPage = newPage;
  obj->currentPage = newPage;
  obj->numberOfPages++;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
  Page* currentPage = obj->currentPage;

  while (steps > 0 && currentPage->prevPage != NULL) {
    currentPage = currentPage->prevPage;
    steps--;
  }

  obj->currentPage = currentPage;

  return currentPage->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
  Page* currentPage = obj->currentPage;

  while (steps > 0 && currentPage->nextPage != NULL) {
    currentPage = currentPage->nextPage;
    steps--;
  }

  obj->currentPage = currentPage;

  return currentPage->url;
}

void browserHistoryFree(BrowserHistory* obj) {
  Page* currentPage = obj->firstPage;
  Page* aux;

  while (currentPage != NULL) {
    aux = currentPage;
    currentPage = currentPage->nextPage;
    free(aux->url);
    free(aux);
  }

  obj->firstPage = NULL;
  obj->lastPage = NULL;
  obj->currentPage = NULL;
  obj->numberOfPages = 0;
}

int main() {
  // Criando o histórico com a página inicial "leetcode.com"
  BrowserHistory* browserHistory = browserHistoryCreate("leetcode.com");

  // Visitando novas páginas
  browserHistoryVisit(browserHistory, "google.com");
  browserHistoryVisit(browserHistory, "facebook.com");
  browserHistoryVisit(browserHistory, "youtube.com");

  // Movendo para trás no histórico
  printf("%s\n", browserHistoryBack(browserHistory, 1));  // Deve retornar "facebook.com"
  printf("%s\n", browserHistoryBack(browserHistory, 1));  // Deve retornar "google.com"

  // Movendo para frente no histórico
  printf("%s\n", browserHistoryForward(browserHistory, 1));  // Deve retornar "facebook.com"

  // Visitando uma nova página (isso deve apagar o histórico à frente)
  browserHistoryVisit(browserHistory, "linkedin.com");

  // Tentando avançar além do limite (não pode ir para frente)
  printf("%s\n", browserHistoryForward(browserHistory, 2));  // Deve retornar "linkedin.com"

  // Movendo para trás 2 páginas
  printf("%s\n", browserHistoryBack(browserHistory, 2));  // Deve retornar "google.com"

  // Tentando mover para trás além do limite
  printf("%s\n", browserHistoryBack(browserHistory, 7));  // Deve retornar "leetcode.com"

  // Liberando memória alocada
  browserHistoryFree(browserHistory);

  return 0;
}
