/* Include files */

#include "template_Final_Project_MPC5643L_sfun.h"
#include "c1_template_Final_Project_MPC5643L.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _template_Final_Project_MPC5643LMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void template_Final_Project_MPC5643L_initializer(void)
{
}

void template_Final_Project_MPC5643L_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_template_Final_Project_MPC5643L_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_template_Final_Project_MPC5643L_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_template_Final_Project_MPC5643L_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2343022007U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1701080882U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1212299135U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3266305856U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(345816494U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(442209070U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(547543925U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2050892155U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_template_Final_Project_MPC5643L_get_check_sum
            (mxArray *plhs[]);
          sf_c1_template_Final_Project_MPC5643L_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2258810623U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(298339321U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2587732746U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4083304268U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2248725612U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2774207527U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(790548743U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(955152031U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_template_Final_Project_MPC5643L_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "b7yWZlfk1NOq5buwjk2aXB") == 0) {
          extern mxArray
            *sf_c1_template_Final_Project_MPC5643L_get_autoinheritance_info(void);
          plhs[0] =
            sf_c1_template_Final_Project_MPC5643L_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_template_Final_Project_MPC5643L_get_eml_resolved_functions_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_template_Final_Project_MPC5643L_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_template_Final_Project_MPC5643L_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void template_Final_Project_MPC5643L_debug_initialize(void)
{
  _template_Final_Project_MPC5643LMachineNumber_ = sf_debug_initialize_machine(
    "template_Final_Project_MPC5643L","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_template_Final_Project_MPC5643LMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_template_Final_Project_MPC5643LMachineNumber_,0);
}

void template_Final_Project_MPC5643L_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_template_Final_Project_MPC5643L_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "template_Final_Project_MPC5643L", "template_Final_Project_MPC5643L");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_template_Final_Project_MPC5643L_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
