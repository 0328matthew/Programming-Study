# Python 예제

파이썬 연습문제 코드가 들어갈 자리입니다. 아직 비어 있습니다.

데스크톱의 `C:\Users\0328m\python_projects` 폴더가 여기에 해당합니다.
(`C++/예제/Chapter 7/.claude/settings.local.json` 에 그 경로가 남아 있어서
존재를 확인했습니다.) 아직 어느 리포지터리에도 올라간 적이 없어서
자동으로 가져오지 못했습니다.

아래처럼 옮기세요 — `-WhatIf` 로 먼저 미리보기 하는 것을 권합니다.

```powershell
cd "C:\Users\0328m\Programming Study"
.\tools\migrate-local-vault.ps1 `
    -Vault "C:\Users\0328m\Programming Study" `
    -PythonProjects "C:\Users\0328m\python_projects" -WhatIf
```

확인이 끝나면 `-WhatIf` 를 빼고 다시 실행한 뒤, 이 파일은 지워도 됩니다.

`C++/예제` 와 같은 규칙으로 챕터별 폴더를 두면 일관됩니다.

```
Python/예제/
├── Chapter 3/
│   └── Problem1.py
└── Chapter 4/
```
