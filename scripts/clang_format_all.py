import os
import subprocess
 
def format_code(file_path):
    clang_format = 'D:/Qt/Tools/QtCreator/bin/clang/bin/clang-format.exe'
    print(file_path)
    command = [clang_format, "-i", "--style=file", file_path]
    subprocess.run(command)

def format_dir(dir):
    exclude_dirs = {'build', 'ThirdParty'}
    src_ext = ['.h', '.hpp', '.hxx', '.hh', '.c', '.cpp', 'cxx', '.cc' ]
    for root, dirs, files in os.walk(dir):
        dirs[:] = [d for d in dirs if d not in exclude_dirs]
        for file_name in files:
            if any([file_name.endswith(ext) for ext in  src_ext]):
                file_path = os.path.join(root, file_name)
                format_code(file_path)
 
def main():
    src_dir = ['src', 'test']
    for dir in src_dir:
        format_dir(dir)
 
if __name__ == '__main__':
    main()