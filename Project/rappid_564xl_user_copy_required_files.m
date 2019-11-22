%%  Author: Yitian Chen
%   date:   3/27/2014
%   task:   copy the c files generated by the S function builder
%           to the project build directory.
function rappid_564xl_user_copy_required_files(dest_dir)
    % annoucement
    disp('### EECS461: user_copy_required_files');
    % get the current directory
    mysource_dir = pwd;
    % get all the c file names
    file_list = dir(fullfile(pwd, '*.c'));
    % copy them into the directory
    for i=1:length(file_list)
        rp_copy(strcat(mysource_dir,filesep,file_list(i,1).name),...
            strcat(dest_dir,filesep, file_list(i,1).name),'f');
    end
    
return