#include"calcfreq.h"
#include"str.h"
	
dictionary* dic_init(int capacity) {
	dictionary* dic = calloc(1,sizeof(dictionary));
	dic->str = calloc(capacity,sizeof(word));
	dic->size = 0;
	dic->capacity=capacity; 
	return dic;
}

void free_dic(dictionary*dic) {
	for (int i=0;i<dic->size;i++){
		free(dic->str[i].s);
	}
	free(dic->str);
	free(dic);
}

int push_back(dictionary*dic,char*string){ 
	if (dic->size == dic->capacity){
		return -1;
	} 
	dic->str[dic->size].s = string ;
	dic->str[dic->size].count = 1;
	dic->size++;
	return 1;
}

int string_finder(dictionary*dic,char*string)
{
	int result;
	for (int i=0;i<dic->size;i++){
		result = scmp(dic->str[i].s,string);

		if (result == 0){
			dic->str[i].count++;

			return 1;
		}
	}
	return 0;
} 


int fill_dic (dictionary*dic,FILE *in){
	char* symbol = calloc(1,sizeof(char));
	char* string = calloc(1,sizeof(char));
	int id=0;
	int result;
	while(fread(symbol,sizeof(char),1,in)){
		if (*symbol == ' '){
			if (id){
				string[id]=0;
				result = string_finder(dic,string);
				if (result == 0){
				push_back(dic,string);
				}
				id = 0;
				string = calloc(1,sizeof(char));
			}
		}else {
			string[id] = *symbol;
			id++;
			string = realloc(string,(id+1)*sizeof(char));
		}
	}
	if (id !=0){
		string[id]=0;
		result = string_finder(dic,string);
		if (result == 0){
			push_back(dic,string);
		}
		else{
		free(string);
		}
	}
	free(symbol);

	return 0;
}


