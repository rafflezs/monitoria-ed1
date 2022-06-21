typedef struct ponteiroSatanico {
  void* ptr_data;
} PonteiroSatanico;

int main() {
  (void*) PonteiroSatanico* pt = malloc(sizeof(PonteiroSatanico));
  (int )pt->ptr_data = (void* )1;
  for(;;){
    pt = realloc(void*)
  }
}

