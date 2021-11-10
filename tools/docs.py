# coding: utf-8
import os
import glob
import shutil

os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    folders = glob.glob('./lib/*')
    for folder in folders:
        files = glob.glob(folder + '/*')
        categoly = folder.split('/')[-1]
        if not os.path.exists('docs/' + categoly):
            os.mkdir('docs/' + categoly)
        for file in files:
            name = file.split('/')[-1]
            doc = 'docs/' + categoly + '/' + name + '.md'
            if not os.path.exists(doc):
                shutil.copyfile('docs/template.md.txt', doc)
            title = name.split('.')[0].split('-')
            for i in range(len(title)):
                title[i] = title[i][0].upper() + title[i][1:]
            title = ' '.join(title)
            replacements = {
                '{% title %}': title,
                '{% hpp %}': '//lib/' + categoly + '/' + name
            }
            cont = []
            with open(doc, mode='r', encoding='utf-8_sig') as f:
                cont = f.readlines()
            for i in range(len(cont)):
                for bef, aft in replacements.items():
                    cont[i] = cont[i].replace(bef, aft)
            with open(doc, mode='w') as f:
                for line in cont:
                    f.write(line)
    return


if __name__ == '__main__':
    main()
