function cell_prop=data_load(path)
    cell_prop = struct;
    
    [num,txt] = xlsread(path,1);
    cell_prop.R_in = struct;
    if length(txt)==0 | txt{1}(1)=='S' | txt{1}(1)=='s'
        [cell_prop.R_in.T,Id_x] = sort(num(1,2:size(num,2)));
        [cell_prop.R_in.SOC,Id_y] = sort(num(2:size(num,1),1)');
        cell_prop.R_in.Rin = num(Id_y+1,Id_x+1);
    else
        [cell_prop.R_in.SOC,Id_x] = sort(num(1,2:size(num,2)));
        [cell_prop.R_in.T,Id_y] = sort(num(2:size(num,1),1)');
        cell_prop.R_in.Rin = num(Id_y+1,Id_x+1);
    end
    
    [num,txt] = xlsread(path,2);
    cell_prop.OCV = struct;
    if length(txt)==0 | txt{1}(1)=='S' | txt{1}(1)=='s'
        [cell_prop.OCV.T, Id_x] = sort(num(1,2:size(num,2)));
        [cell_prop.OCV.SOC, Id_y] = sort(num(2:size(num,1),1)');
        cell_prop.OCV.ocv = num(Id_y+1,Id_x+1);
    else
        [cell_prop.OCV.SOC, Id_x] = sort(num(1,2:size(num,2)));
        [cell_prop.OCV.T, Id_y] = sort(num(2:size(num,1),1)');
        cell_prop.OCV.ocv = num(Id_y+1,Id_x+1);
    end
    
    [num,txt]=xlsread(path,3);
    cell_prop.Cap_ini = num(1,1);
    cell_prop.T_ext = num(2,1)+273.15;
    cell_prop.m_cell = num(3,1);
    cell_prop.cell_length = num(4,1);
    cell_prop.cell_width = num(5,1);
    cell_prop.cell_height = num(6,1); 
    cell_prop.CFM = num(7,1); 
    cell_prop.wall = num(8,1); 