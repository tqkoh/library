---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# coding: utf-8\n# verification-helper: IGNORE\nimport os\nimport glob\n\
    import shutil\n\nos.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))\n\
    \n\ndef main():\n    folders = glob.glob('./lib/*')\n    for folder in folders:\n\
    \        files = glob.glob(folder + '/*')\n        categoly = folder.split('/')[-1]\n\
    \        if not os.path.exists('docs/' + categoly):\n            os.mkdir('docs/'\
    \ + categoly)\n        for file in files:\n            name = file.split('/')[-1]\n\
    \            doc = 'docs/' + categoly + '/' + name + '.md'\n            if not\
    \ os.path.exists(doc):\n                shutil.copyfile('docs/template.md.txt',\
    \ doc)\n            title = name.split('.')[0].split('-')\n            for i in\
    \ range(len(title)):\n                title[i] = title[i][0].upper() + title[i][1:]\n\
    \            title = ' '.join(title)\n            replacements = {\n         \
    \       '{% title %}': title,\n                '{% hpp %}': '//lib/' + categoly\
    \ + '/' + name\n            }\n            cont = []\n            with open(doc,\
    \ mode='r', encoding='utf-8_sig') as f:\n                cont = f.readlines()\n\
    \            for i in range(len(cont)):\n                for bef, aft in replacements.items():\n\
    \                    cont[i] = cont[i].replace(bef, aft)\n            with open(doc,\
    \ mode='w') as f:\n                for line in cont:\n                    f.write(line)\n\
    \    return\n\n\nif __name__ == '__main__':\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/docs.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/docs.py
layout: document
redirect_from:
- /library/tools/docs.py
- /library/tools/docs.py.html
title: tools/docs.py
---
