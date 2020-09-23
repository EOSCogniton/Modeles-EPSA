Inner_Batterie_Model | Read-Me

	version 1.0  @JZU_20200920_EPSA

0/ Make sure all the model and datasheet in the same dictory

1/ For the first use, please launch the initialisation of the extended model firstly.
	>> extend_model_ini.m % in Matlab Script

2/ After the initialisation, you can modifier the DataSheet in format of 'Cell_data.xlsx' and change the configuration with your own batterie model ('Model_Simple.slx' is a viso-library for the emparked cell model, you can use it by copy-paste.) Then, you can launch these code :
	>> cell_prop=data_load('DataSheetName'); % DataSheetName with '.xls(x)' (ex: 'Cell_data.xlsx' for the sheet 'Cell_data.xlsx')
                	                                                    % If you've just finished the initialisation, you can skip this step 
	>> sim('ModelName',SimulationTime); % ModelName without '.slx(c)' (ex: 'BMS_detect' for the model 'BMS_detect.slx')
	>> Result_Analysor
Or, just by one line if the simulation time is long:
	>> cell_prop=data_load('DataSheetName'); sim('ModelName',SimulationTime); Result_Analysor


Enjoy your use !