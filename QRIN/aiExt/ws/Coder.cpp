// Name:     Coder.cpp
// Author:   Anureet Saxena
//           Tepper School of Business 
//           Carnegie Mellon University, Pittsburgh, PA 15213
//           email: anureets@andrew.cmu.edu
//-----------------------------------------------------------------------------
// Copyright (C) 2004, Anureet Saxena. All Rights Reserved.
//-----------------------------------------------------------------------------

#ifndef ASX_Coder_cpp
#define ASX_Coder_cpp

#include <iostream>
#include <stdio.h>
#include <string.h>

class Coder	{

/**	This allows one to develp codes faster, efficiently and bugfree*/

private:
/**	Data Members */
	
   char* nameSpace;
	char* className;
	char** superclass_arr;
	int nsuperclass_arr;

	char** include_fNames;
	int ninclude_fNames;
	char** include_namespaces;
	int ninclude_namespaces;

	bool init_required;
	bool reset_required;
	bool fprint_required;
	bool fscan_required;

	char** datatypes_arr;
	char** datanames_arr;
	bool* memclean_arr; //indicates whether the corresponding data type will involve (de)allocating memory
	bool* reset_arr; //indicates whether the corresponding object has to be reset
	bool* fprint_arr; //indicates whether the corresponding object has to be fprint
	bool* fscan_arr; //indicates whether the corresponding object has to be fscan
	bool* init_arr; //indicates whether the corresponding object has to be initialized 
	bool* set_arr; //indicates whether the corresponding object will have a set function
	bool* constType_arr; //indicates whether the corresponding object is of const type
	bool* init_NULL_arr; //indicates whether the corresponding object has to be set to NULL in init_NULL
	int ndatatypes;

protected: 
/**	Protected Data Access functions */
	void read_ip(char* str,FILE* fp,const char* outFName);

public:
	//Constructors
	Coder();

	//Initializer
	virtual void init_Coder();

	void getData(FILE* fp=stdin);
	void construct_hpp_file();
	void construct_cpp_file();

	bool isSimpleDataType(const char* type);

};

Coder::Coder()	{init_Coder();}

void Coder::init_Coder()	{

	int i;

	nameSpace =new char[100];
	className=new char[100];
	superclass_arr=new char*[100];
	for(i=0;i<100;i++) superclass_arr[i]=new char[100];
	nsuperclass_arr=0;

	include_fNames=new char*[100];
	for(i=0;i<100;i++) include_fNames[i]=new char[100];
	ninclude_fNames=0;

	include_namespaces=new char*[100];
	for(i=0;i<100;i++) include_namespaces[i]=new char[100];
	ninclude_namespaces=0;

	datatypes_arr=new char*[100];
	for(i=0;i<100;i++) datatypes_arr[i]=new char[100];

	datanames_arr=new char*[100];
	for(i=0;i<100;i++) datanames_arr[i]=new char[100];

	memclean_arr=new bool[100];
	reset_arr=new bool[100];
	fprint_arr=new bool[100];
	fscan_arr=new bool[100];
	init_arr=new bool[100];
	init_NULL_arr=new bool[100];
	set_arr=new bool[100];
	constType_arr=new bool[100];
	ndatatypes=0;

}

void Coder::read_ip(char* str,FILE* fp,const char* outFName)	{

	fscanf(fp,"%s",str);
	if(outFName!=NULL)	{
		FILE* fp_out=fopen(outFName,"a");
		fprintf(fp_out,"%s\n",str);
		fclose(fp_out);
	}

}

void Coder::getData(FILE* fp)	{

	char str[100]="";
	int num,i;
	char* outFName=NULL;

	printf("Do you need a bacup file (y/n):");
	fscanf(fp,"%s",str);
	printf("\n");
	if(strcmp(str,"y")==0)	{
		printf("Enter bacup file name: ");
		outFName=new char[100];
		fscanf(fp,"%s",outFName);
		printf("\n");
		FILE* fp_out=fopen(outFName,"a");
		fprintf(fp_out,"n\n");
		fclose(fp_out);
	}

	printf("Do you need initialization of variables (y/n): ");
	read_ip(str,fp,outFName);
	printf("\n");
	if(strcmp(str,"y")==0) init_required=true;
	else init_required=false;

	printf("Do you need resetting of variables (y/n): ");
	read_ip(str,fp,outFName);
	printf("\n");
	if(strcmp(str,"y")==0) reset_required=true;
	else reset_required=false;

	printf("Do you need fprinting of variables (y/n): ");
	read_ip(str,fp,outFName);
	printf("\n");
	if(strcmp(str,"y")==0) fprint_required=true;
	else fprint_required=false;

	printf("Do you need fscaning of variables (y/n): ");
	read_ip(str,fp,outFName);
	printf("\n");
	if(strcmp(str,"y")==0) fscan_required=true;
	else fscan_required=false;

	printf("Enter the include_fNames (end to stop): ");
	printf("\n");

	while(1==1)	{
		printf("Enter the %d file to include : ",ninclude_fNames+1);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"end")==0) break;
		sprintf(include_fNames[ninclude_fNames++],"%s",str);
	}

	printf("Enter the include_namespaces (end to stop): ");
	printf("\n");

	while(1==1)	{
		printf("Enter the %d file to include : ",ninclude_namespaces+1);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"end")==0) break;
		sprintf(include_namespaces[ninclude_namespaces++],"%s",str);
	}
	printf("---------------------------------\n");

	printf("Enter the nameSpace: ");
	read_ip(str,fp,outFName);
	printf("\n");
	sprintf(nameSpace,"%s",str);

	printf("Enter the className: ");
	read_ip(str,fp,outFName);
	printf("\n");
	sprintf(className,"%s",str);

	printf("Enter the Superclasses (end to stop): ");
	printf("\n");

	while(1==1)	{
		printf("Enter the %d Superclass : ",nsuperclass_arr+1);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"end")==0) break;
		sprintf(superclass_arr[nsuperclass_arr++],"%s",str);
	}
	printf("---------------------------------\n");

	printf("Enter the Data Members (end to stop): ");
	printf("\n");

	while(1==1)	{
		printf("Enter the %d Data Member Name : ", ndatatypes+1);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"end")==0) break;
		sprintf(datanames_arr[ndatatypes],"%s",str);

		printf("Enter the %s Type : ", datanames_arr[ndatatypes]);
		read_ip(str,fp,outFName);
		printf("\n");
		sprintf(datatypes_arr[ndatatypes],"%s",str);

		if(!isSimpleDataType(datatypes_arr[ndatatypes]))	{
			printf("Would %s require memory allocation/deallocation (y/n): ", datanames_arr[ndatatypes]);
			read_ip(str,fp,outFName);
			printf("\n");
			if(strcmp(str,"y")==0) memclean_arr[ndatatypes]=true;
			else memclean_arr[ndatatypes]=false;
		}
		else memclean_arr[ndatatypes]=false;

		printf("Would %s require initialization (y/n) : ", datanames_arr[ndatatypes]);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"y")==0) init_arr[ndatatypes]=true;
		else init_arr[ndatatypes]=false;


		if(!isSimpleDataType(datatypes_arr[ndatatypes]))	{
			printf("Would %s require init_NULL (y/n) : ", datanames_arr[ndatatypes]);
			read_ip(str,fp,outFName);
			printf("\n");
			if(strcmp(str,"y")==0) init_NULL_arr[ndatatypes]=true;
			else init_NULL_arr[ndatatypes]=false;
		}
		else init_NULL_arr[ndatatypes]=false;

		printf("Would %s require set function (y/n) : ", datanames_arr[ndatatypes]);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"y")==0) set_arr[ndatatypes]=true;
		else set_arr[ndatatypes]=false;


		if(reset_required)	{
			printf("Would %s require resetting (y/n) : ", datanames_arr[ndatatypes]);
			read_ip(str,fp,outFName);
			printf("\n");
			if(strcmp(str,"y")==0) reset_arr[ndatatypes]=true;
			else reset_arr[ndatatypes]=false;
		}

		if(fprint_required)	{
			printf("Would %s require fprinting (y/n) : ", datanames_arr[ndatatypes]);
			read_ip(str,fp,outFName);
			printf("\n");
			if(strcmp(str,"y")==0) fprint_arr[ndatatypes]=true;
			else fprint_arr[ndatatypes]=false;
		}

		if(fscan_required)	{
			printf("Would %s require fscaning (y/n) : ", datanames_arr[ndatatypes]);
			read_ip(str,fp,outFName);
			printf("\n");
			if(strcmp(str,"y")==0) fscan_arr[ndatatypes]=true;
			else fscan_arr[ndatatypes]=false;
		}

		printf("Is %s of const type (y/n) : ", datanames_arr[ndatatypes]);
		read_ip(str,fp,outFName);
		printf("\n");
		if(strcmp(str,"y")==0) constType_arr[ndatatypes]=true;
		else constType_arr[ndatatypes]=false;

		ndatatypes++;

	}
	printf("---------------------------------\n");
	printf("Done Taking the Data\n");
	printf("---------------------------------\n");
	
}

void Coder::construct_hpp_file()	{

	int i;

	char fName[100]="";
	sprintf(fName,"%s.hpp",className);
	FILE* fp=fopen(fName,"a");
	if(fp==NULL) {printf("Could nt open %s for appending\n",fName); exit(-1);}

	char ext[100]="";
	sprintf(ext,"hpp");

	char name[100];
	sprintf(name,"Anureet Saxena");
	
	fprintf(fp,"// Name:     %s\n",fName);
	fprintf(fp,"// Author:   %s\n",name);
	fprintf(fp,"//-----------------------------------------------------------------------------\n");
	fprintf(fp,"#ifndef ASX_%s_%s\n",className,ext); 
	fprintf(fp,"#define ASX_%s_%s\n",className,ext);
	fprintf(fp,"\n");
   fprintf(fp,"namespace %s {\n",nameSpace);
	fprintf(fp,"//Forword decalaration\n");
	fprintf(fp,"class %s;\n",className);
   fprintf(fp,"};\n\n");
   fprintf(fp,"#include \"Utils.hpp\"\n");
   fprintf(fp,"#include \"Utils_templates.hpp\"\n");
   for(i=0;i<ninclude_fNames;i++)	{
		fprintf(fp,"#include \"%s\"\n",include_fNames[i]);
	}
	fprintf(fp,"\n");
   fprintf(fp,"using namespace std;\n");
   fprintf(fp,"using namespace aiUtils;\n");
   for(i=0;i<ninclude_namespaces;i++)	{
		fprintf(fp,"using namespace %s;\n",include_namespaces[i]);
	}
   fprintf(fp,"using namespace %s;\n",nameSpace);
	fprintf(fp,"\n");
	fprintf(fp,"\n");

	
	fprintf(fp,"//Parameters/////////////////////////////\n");
	fprintf(fp,"/////////////////////////////////////////\n");
	fprintf(fp,"\n");

   fprintf(fp,"namespace %s {\n\n",nameSpace);

	fprintf(fp,"class %s",className);
	
	if(nsuperclass_arr!=0)	{
		fprintf(fp," : ");
		for(i=0;i<nsuperclass_arr;i++)	{
			fprintf(fp,"public %s ",superclass_arr[i]);
			if(i!=nsuperclass_arr-1) fprintf(fp,", ");
		}
	}

	fprintf(fp," {\n");
	fprintf(fp,"\n");
	fprintf(fp,"/**\n");
	fprintf(fp," * \tClass Description:\n");
	fprintf(fp," * \t\tNone\n");
	fprintf(fp," * \n");
	fprintf(fp," * \tAssumptions:\n");
	fprintf(fp," * \t\tNone\n");
	fprintf(fp," * \n");
	fprintf(fp," * \tObjects:\n");
	fprintf(fp," * \t\tNone\n");
	fprintf(fp," * \n");
	fprintf(fp," * \tOwnership:\n");
	fprintf(fp," * \t\tAll objects owned\n");
	fprintf(fp," * \n");
	fprintf(fp," */\n");
	fprintf(fp,"\n");
	fprintf(fp,"private:\n");
	fprintf(fp,"/**\tData Members */\n");	

	if(ndatatypes!=0)	{
		for(i=0;i<ndatatypes;i++)	{
			fprintf(fp,"\t");
			if(constType_arr[i])	fprintf(fp,"const ");
			fprintf(fp,"%s _%s;\n",datatypes_arr[i],datanames_arr[i]);
		}
	}

	fprintf(fp,"\n");
	fprintf(fp,"protected: \n");
	fprintf(fp,"\n\t/** Protected Constructors */\n");
	fprintf(fp,"\t%s();\n",className);
	fprintf(fp,"\t%s(const %s* ptr);\n",className,className);
	fprintf(fp,"\t%s(const %s& obj);\n",className,className);
	fprintf(fp,"\n");
	fprintf(fp,"/**\tinit_NULL initializes all memory related data members to \n");
	fprintf(fp,"\tNULL to make sure nothing is left unclean when copy or any\n");
	fprintf(fp,"\tother function is called This function must NOT be virtual*/\n");
	fprintf(fp,"\tvoid init_NULL();\n");
	fprintf(fp,"\n");


	fprintf(fp,"public:\n");
	fprintf(fp,"\n");
	fprintf(fp,"\t//Initializer\n");
	fprintf(fp,"\tvirtual void init();\n");
	fprintf(fp,"\tvoid init_%s();\n",className);

	if(init_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(! init_arr[i]) continue;
			fprintf(fp,"\tvirtual void init_%s();\n",datanames_arr[i]);
		}
	}
	fprintf(fp,"\n");

	fprintf(fp,"\t//Destructor\n");
	fprintf(fp,"\tvirtual ~%s(); \n",className);
	fprintf(fp,"\n\t /** Memory Clean Up functions*/\n");
	fprintf(fp,"\tvirtual void cleanMem(); \n");
	fprintf(fp,"\tvoid cleanMem_%s(); \n",className);
	for(i=0;i<ndatatypes;i++)	{
		if(!memclean_arr[i]) continue;
		fprintf(fp,"\tvirtual void cleanMem_%s();\n",datanames_arr[i]);
	}

	fprintf(fp,"\n\t/** Public Data Access Functions */\n");
	for(i=0;i<ndatatypes;i++)	{
		fprintf(fp,"\t");
		fprintf(fp,"virtual %s ",datatypes_arr[i]);
		fprintf(fp,"%s();\n",datanames_arr[i]);
	}

   fprintf(fp,"\n");
	fprintf(fp,"\t/** Public data Set functions */\n");
	for(i=0;i<ndatatypes;i++)	{
		if(! set_arr[i]) continue;
		fprintf(fp,"\tvirtual void set_%s(%s _obj);\n",datanames_arr[i], datatypes_arr[i]);
	}
	fprintf(fp,"\n");

	fprintf(fp,"\t//Access classname dynamically \n");
	fprintf(fp,"\tvirtual string className() const;\n");
	fprintf(fp,"\n");
	fprintf(fp,"\t//For error message handling\n");
	fprintf(fp,"\tvoid myerr_msg(string msg, string func);\n");
	fprintf(fp,"\n");
	fprintf(fp,"\t//Printing and Scaning Options\n");
	fprintf(fp,"\tvirtual void fprint(string fname);\n");
	fprintf(fp,"\tvoid fprint_%s(string fname);\n",className);
	fprintf(fp,"\tvirtual void fscan(string fname);\n");
	fprintf(fp,"\tvoid fscan_%s(string fname);\n",className);
	fprintf(fp,"\n");
	fprintf(fp,"\t//Reset\n");
	fprintf(fp,"\tvirtual void reset();\n");
	fprintf(fp,"\tvoid reset_%s();\n",className);
	if(reset_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(!reset_arr[i]) continue;
			fprintf(fp,"\tvirtual void reset_%s();\n",datanames_arr[i]);
		}
	}

	fprintf(fp,"\n");
	fprintf(fp,"\n\t/** ------ Static Functions ----------------*/\n");
	fprintf(fp,"\n\tstatic %s* instance();\n",className);
	fprintf(fp,"\n\tstatic %s* instance_fscan(string fname);\n",className);
   fprintf(fp,"\n");

	fprintf(fp,"\t/** ----------  Non-standard functions start here -----------*/\n\n");
	fprintf(fp,"};\n");
	fprintf(fp,"\n");
	fprintf(fp,"};\n");
	fprintf(fp,"\n");
	fprintf(fp,"#endif\n\n");

	fclose(fp);
}


void Coder::construct_cpp_file()	{

	int i;

	char fName[100]="";
	sprintf(fName,"%s.cpp",className);
	FILE* fp=fopen(fName,"a");
	if(fp==NULL) {printf("Could not open %s for appending\n",fName); exit(-1);}

	char ext[100]="";
	sprintf(ext,"cpp");

	char name[100];
	sprintf(name,"Anureet Saxena");
	
	fprintf(fp,"// Name:     %s\n",fName);
	fprintf(fp,"// Author:   %s\n",name);
	fprintf(fp,"//-----------------------------------------------------------------------------\n");
	fprintf(fp,"#ifndef ASX_%s_%s\n",className,ext); 
	fprintf(fp,"#define ASX_%s_%s\n",className,ext);
	fprintf(fp,"\n");
	fprintf(fp,"\n");
	fprintf(fp,"#include <stdio.h>\n");
   fprintf(fp,"#include \"Utils.hpp\"\n");
   fprintf(fp,"#include \"Utils_templates.hpp\"\n");
	for(i=0;i<ninclude_fNames;i++)	{
		fprintf(fp,"#include \"%s\"\n",include_fNames[i]);
	}
	fprintf(fp,"#include \"%s.hpp\"\n",className);
	fprintf(fp,"\n");
   fprintf(fp,"using namespace std;\n");
   fprintf(fp,"using namespace aiUtils;\n");
   fprintf(fp,"using namespace %s;\n",nameSpace);
	for(i=0;i<ninclude_namespaces;i++)	{
		fprintf(fp,"using namespace %s;\n",include_namespaces[i]);
	}
	fprintf(fp,"\n");

	fprintf(fp,"/** --------------Constructors and init_NULL-----------*/\n\n");
	fprintf(fp,"%s::%s() { init_NULL(); }\n",className,className);
	fprintf(fp,"%s::%s(const %s* ptr) { myerr_msg(\"copy functionality disabled\",__FUNCTION__); }\n",className,className,className);
	fprintf(fp,"%s::%s(const %s& ptr) { myerr_msg(\"copy functionality disabled\",__FUNCTION__); }\n",className,className,className);
	fprintf(fp,"\n");
	fprintf(fp,"void %s::init_NULL()\t{\n",className);
	for(i=0;i<ndatatypes;i++)	{
		if(!init_NULL_arr[i]) continue;
		fprintf(fp,"\t_%s=NULL;\n",datanames_arr[i]);
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	fprintf(fp,"/** ---Public Data Setting Functions-----------------*/\n\n");
	for(i=0;i<ndatatypes;i++)	{
		if(! set_arr[i]) continue;
		fprintf(fp,"void %s::set_%s(%s _obj) {\n",className,datanames_arr[i],datatypes_arr[i]);
		if( isSimpleDataType(datatypes_arr[i]) )	{
			fprintf(fp,"\t_%s=_obj;\n",datanames_arr[i]);
		}
		else	{
			fprintf(fp,"\tprintf(\"Setting for _%s in class %s not implemented\\n\");\n",datanames_arr[i],className);
		}
		fprintf(fp,"}\n");
		fprintf(fp,"\n");
	}

	fprintf(fp,"/** --------   Init Functions -------------------------*/\n\n");

	fprintf(fp,"void %s::init() {\n",className);
	fprintf(fp,"\t//Insert calls to super.init() here\n");
	fprintf(fp,"\tinit_%s();\n",className);
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"void %s::init_%s() {\n",className,className);
	if(init_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(! init_arr[i]) continue;
			fprintf(fp,"\tinit_%s();\n",datanames_arr[i]);
		}
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	if(init_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(! init_arr[i]) continue;
			fprintf(fp,"void %s::init_%s() {\n",className,datanames_arr[i]);
			fprintf(fp,"\tprintf(\"Initialized for %s in class %s not implemented\\n\");\n",datanames_arr[i],className);
			fprintf(fp,"}\n");
			fprintf(fp,"\n");
		}
	}

	fprintf(fp,"/** -----Destructors and Memory Cleanup functions -----*/\n\n");
	fprintf(fp,"%s::~%s()\t{ cleanMem(); }\n",className,className);
	fprintf(fp,"\n");
	fprintf(fp,"void %s::cleanMem()\t{\n",className);
	fprintf(fp,"\tcleanMem_%s();\n",className);
   for(int i=0;i<nsuperclass_arr;i++) {
      fprintf(fp,"\t%s::cleanMem();\n",superclass_arr[i]);
   }
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"void %s::cleanMem_%s() {\n",className,className);
	for(i=0;i<ndatatypes;i++)	{
		if(!memclean_arr[i]) continue;
		fprintf(fp,"\tcleanMem_%s();\n",datanames_arr[i]);
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	for(i=0;i<ndatatypes;i++)	{
		if(!memclean_arr[i]) continue;
		fprintf(fp,"void %s::cleanMem_%s() {\n",className, datanames_arr[i]);
		fprintf(fp,"\tprintf(\"cleanMem for %s in class %s not implemented\\n\");\n",datanames_arr[i],className);
		fprintf(fp,"\t_%s=NULL;\n",datanames_arr[i]);
		fprintf(fp,"}\n");
		fprintf(fp,"\n");
	}

	fprintf(fp,"/** ------------- Data Access Functions --------------------*/\n\n");
	for(i=0;i<ndatatypes;i++)	{
		fprintf(fp,"%s ",datatypes_arr[i]);
		fprintf(fp,"%s::%s() {return _%s;}\n",className,datanames_arr[i],datanames_arr[i]);
	}
	fprintf(fp,"\n");

	fprintf(fp,"/** ------------- Access classname dynamically --------------------*/\n\n");
	fprintf(fp,"string %s::className() const {return \"%s\";}\n",className,className);
	fprintf(fp,"\n");
   fprintf(fp,"/** ------------- Error Message Handling Functions ------------------*/\n\n");
   fprintf(fp,"void %s::myerr_msg(string msg, string func) {\n",className);
   fprintf(fp,"\terr_msg(\"%s::\",func,\" \",msg);\n",className);
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"/** ------------- Printing and Scanning Options ------------------*/\n\n");
   fprintf(fp,"void %s::fprint(string fname) {\n",className);
   for(int i=0;i<nsuperclass_arr;i++) {
      fprintf(fp,"\t%s::fprint(fname);\n",superclass_arr[i]);
   }
	fprintf(fp,"\tfprint_%s(fname);\n",className);
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"void %s::fprint_%s(string fname) {\n",className,className);
	if(fprint_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(!fprint_arr[i]) continue;
         if(isSimpleDataType(datatypes_arr[i])) {
            fprintf(fp,"\tutil_ofprint(fname,\"%s\",_%s);\n",datanames_arr[i],datanames_arr[i]);
         }
         else {
            fprintf(fp,"\tutil_ofprint_obj(fname,\"%s\",_%s);\n",datanames_arr[i],datanames_arr[i]);
         }
		}
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	fprintf(fp,"void %s::fscan(string fname) {\n",className);
   for(int i=0;i<nsuperclass_arr;i++) {
      fprintf(fp,"\t%s::fscan(fname);\n",superclass_arr[i]);
   }
	fprintf(fp,"\tfscan_%s(fname);\n",className);
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"void %s::fscan_%s(string fname) {\n",className,className);
	if(fscan_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(!fscan_arr[i]) continue;
         if(isSimpleDataType(datatypes_arr[i])) {
            fprintf(fp,"\tutil_ofscan(fname,\"%s\",_%s);\n",datanames_arr[i],datanames_arr[i]);
         }
         else  fprintf(fp,"\t//Insert scanning function for %s here\n",datanames_arr[i]);
		}
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");


	fprintf(fp,"/** ------------- Reset Functions --------------------*/\n\n");

	fprintf(fp,"void %s::reset() {\n",className);
	fprintf(fp,"\treset_%s();\n",className);
   for(int i=0;i<nsuperclass_arr;i++) {
      fprintf(fp,"\t%s::reset();\n",superclass_arr[i]);
   }
	fprintf(fp,"}\n");
	fprintf(fp,"\n");
	fprintf(fp,"void %s::reset_%s() {\n",className,className);
	if(reset_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(!reset_arr[i]) continue;
			fprintf(fp,"\treset_%s();\n",datanames_arr[i]);
		}
	}
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	if(reset_required)	{
		for(i=0;i<ndatatypes;i++)	{
			if(!reset_arr[i]) continue;
			fprintf(fp,"void %s::reset_%s() {\n",className,datanames_arr[i]);
			fprintf(fp,"\tprintf(\"reset for %s in class %s not implemented\\n\");\n",datanames_arr[i],className);
			fprintf(fp,"}\n");
			fprintf(fp,"\n");
		}
	}

	
	fprintf(fp,"/** ----------  static instance function -----------*/\n\n");
	fprintf(fp,"\n%s* %s::instance()\t{\n",className,className);
	fprintf(fp,"\t%s* ptr=new %s();\n",className,className);	
	fprintf(fp,"\tptr->init();\n");
	fprintf(fp,"\treturn ptr;\n");
	fprintf(fp,"}\n");
	fprintf(fp,"\n");

	fprintf(fp,"\n%s* %s::instance_fscan(string fname)\t{\n",className,className);
	fprintf(fp,"\t%s* ptr=NULL;\n",className);
   fprintf(fp,"\tif(!util_fscan_NULL(fname)) {\n");
   fprintf(fp,"\t\tptr=new %s();\n",className);	
   fprintf(fp,"\t\tptr->init_NULL();\n");
   fprintf(fp,"\t\tptr->fscan(fname);\n");
   fprintf(fp,"\t}\n");
   fprintf(fp,"\treturn ptr;\n");
   fprintf(fp,"}\n");
   fprintf(fp,"\n");

   fprintf(fp,"/** ----------  Non-standard functions start here -----------*/\n\n");

	fprintf(fp,"#endif\n\n");
	fclose(fp);
}


bool Coder::isSimpleDataType(const char* type)	{

	if(strcmp(type,"int")==0) return true;
	if(strcmp(type,"double")==0) return true;
	if(strcmp(type,"bool")==0) return true;
	if(strcmp(type,"float")==0) return true;
	if(strcmp(type,"string")==0) return true;

	return false;
}
	

int main()	{

	Coder cd;
	printf("Getting Data :-\n");
	cd.getData();
	printf("Constructing .hpp file\n");
	cd.construct_hpp_file();
	printf("Constructing .cpp file\n");
	cd.construct_cpp_file();
	printf("Done\n");
}

#endif

