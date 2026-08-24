# Programming Study

프로그래밍 학습용 Obsidian 볼트. 언어별 **대분류 폴더** 아래에 **개념**(노트)과
**예제**(연습문제 코드)를 나눠 둡니다.

기존에 흩어져 있던 `CPP-Study`, `cpp_project`, `Python-Study` 세 리포지터리를
커밋 히스토리까지 그대로 가져와 하나로 합친 것입니다.

## 구조

```
Programming Study/
├── C++/
│   ├── 개념/          ← 이론 노트 (구 CPP-Study)
│   └── 예제/          ← 연습문제 코드 (구 cpp_project)
│       ├── Chapter 3/ … Chapter 7/
│       └── …
├── Python/
│   ├── 개념/          ← 이론 노트 (구 Python-Study)
│   └── 예제/          ← 연습문제 코드 (구 python_projects — 로컬에서 복사)
├── .vscode/           ← MSYS2 UCRT64 빌드·디버그 설정, 자동 동기화 태스크
├── tools/             ← 자동 커밋·푸시 스크립트
└── docs/              ← 설정 가이드
```

새 언어를 추가할 때도 같은 규칙을 씁니다 — `<언어>/개념`, `<언어>/예제`.

## 이 볼트의 범위

**프로그래밍·CS 관련 노트는 전부 여기에 둡니다.**
역학·응용수학은 [llm-wiki](https://github.com/0328matthew/llm-wiki) 볼트가 맡습니다.

llm-wiki 에 있던 `35-CS/` (C++ 객체지향 20장 · 구조적 접근 14장 · OS 개발)
는 2026-08-24 에 정리했습니다. 다시 쓸 때 참고가 필요하면 그 리포지터리의
히스토리에서 꺼낼 수 있습니다.

```powershell
git -C ..\llm-wiki checkout 1a120e8 -- "35-CS/Cpp-OOP/OOP Ch07 사용자 정의 자료형 — 클래스.md"
```

## 자동 커밋·푸시

VS Code 로 볼트를 열면 백그라운드 동기화가 자동으로 뜹니다. 편집을 멈추고
20초쯤 지나면 알아서 커밋하고 푸시합니다. 창을 닫는 순간까지 확실히
보장하려면 `tools\study.cmd` 로 여세요.

설정 방법은 **[docs/자동-푸시-설정.md](docs/자동-푸시-설정.md)** 를 보세요.

## C++ 빌드

볼트 루트를 VS Code 로 열고 `.cpp` 파일에서 `Ctrl+Shift+B`.
컴파일러는 `C:/msys64/ucrt64/bin/g++.exe` (C++20) 를 씁니다.
`F5` 로 gdb 디버깅도 됩니다.

빌드 결과물(`.exe`)은 `.gitignore` 로 제외되어 커밋되지 않습니다.
통합 이전에 커밋됐던 `.exe` 들은 히스토리에 그대로 남아 있습니다.

## 관련 문서

| 문서 | 내용 |
|---|---|
| [docs/자동-푸시-설정.md](docs/자동-푸시-설정.md) | VS Code·Obsidian 자동 동기화 설정 |
| [docs/기존-리포지터리-정리.md](docs/기존-리포지터리-정리.md) | 옛 리포지터리 3개를 안전하게 삭제하는 절차 |
