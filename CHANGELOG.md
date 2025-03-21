# Changelog

## [0.3.5](https://github.com/hwakabh/echo-server/compare/v0.3.4...v0.3.5) (2025-03-21)


### Bug Fixes

* typo in checksum file. ([0a6e057](https://github.com/hwakabh/echo-server/commit/0a6e057b6fa48654c22836eed4db2f79f9a6a02f))


### Miscellaneous Chores

* reverted back job separations. ([c213abe](https://github.com/hwakabh/echo-server/commit/c213abe7b0f7c6aedddaf1c54dbede68ed6388cf))

## [0.3.4](https://github.com/hwakabh/echo-server/compare/v0.3.3...v0.3.4) (2025-03-21)


### Bug Fixes

* included checksum generation into compile process. ([c649429](https://github.com/hwakabh/echo-server/commit/c649429c241d90eb126a19c2973b2f9442aeae14))
* included checksum generation into compile process. ([8d151c9](https://github.com/hwakabh/echo-server/commit/8d151c9205860df96995a7c46d9535db59c4278e))


### Miscellaneous Chores

* renamed job for uploadings. ([2d0acc0](https://github.com/hwakabh/echo-server/commit/2d0acc0e5677cb0ae9b4aacc796f97df61d919be))

## [0.3.3](https://github.com/hwakabh/echo-server/compare/v0.3.2...v0.3.3) (2025-03-21)


### Continuous Integration

* enabled to include checksum file in release. ([f9daef7](https://github.com/hwakabh/echo-server/commit/f9daef755065bc978d78fd2628ff7862a878a2af))
* enabled to include checksum file in release. ([db6b0e2](https://github.com/hwakabh/echo-server/commit/db6b0e275be63ce14109bab06ce7756a05068c47))

## [0.3.2](https://github.com/hwakabh/echo-server/compare/v0.3.1...v0.3.2) (2025-03-21)


### Miscellaneous Chores

* **ci:** enabled to use PAT instread of workflow default token. ([6ae27ca](https://github.com/hwakabh/echo-server/commit/6ae27ca4194efe62409066cdc855090ed8ea8c63))
* **ci:** enabled to use PAT instread of workflow default token. ([4648f7b](https://github.com/hwakabh/echo-server/commit/4648f7b7d237d8eb29bb754319719ea605309e99))

## [0.3.1](https://github.com/hwakabh/echo-server/compare/v0.3.0...v0.3.1) (2025-03-21)


### Miscellaneous Chores

* **deps:** update docker/login-action action to v3.4.0 ([f75ec03](https://github.com/hwakabh/echo-server/commit/f75ec03b07883a6a1c3f7193df472c85ec091380))
* fixed debugging triggers and made tag name as dynamic values. ([c97be6d](https://github.com/hwakabh/echo-server/commit/c97be6debc418b1fb2b2ac1f4023b6c39ed12d7a))
* updated with static tags for debugging. ([a34935b](https://github.com/hwakabh/echo-server/commit/a34935bd72f7348cde2c934666b91d7a7a083901))


### Continuous Integration

* added workflow for uploading assets to release ([cfcf2d1](https://github.com/hwakabh/echo-server/commit/cfcf2d1581a2addd0a42fbab53361150366cdd0c))
* added workflows for uploading assets to release. ([59d4925](https://github.com/hwakabh/echo-server/commit/59d49252f359b7cea174b575c1ced6314751aca5))
* added workflows for uploading assets to release. ([e0b9308](https://github.com/hwakabh/echo-server/commit/e0b9308ee0dc954ff1345834cac9e8863af39d5c))
* added workflows for uploading assets to release. ([8bcc932](https://github.com/hwakabh/echo-server/commit/8bcc932b175f9f7997a237231a33495dce0e8c22))

## [0.3.0](https://github.com/hwakabh/echo-server/compare/v0.2.0...v0.3.0) (2025-03-06)


### Features

* added logics of closed-loop for serving application as daemon. ([b2134fe](https://github.com/hwakabh/echo-server/commit/b2134fed8cc0aa4608d77aa0c343924d6d051967))
* added logics of closed-loop for serving application as daemon. ([5c91063](https://github.com/hwakabh/echo-server/commit/5c910639b45b19c63fc2aec743f8df28f056d423))
* added validations with maximum port number. ([f8b9903](https://github.com/hwakabh/echo-server/commit/f8b9903da71ac842c63f6c4eb29e0185f13a58ab))
* added validations with maximum port number. ([8729dc1](https://github.com/hwakabh/echo-server/commit/8729dc141a0f3af543e77c242f8a118866bb401b))


### Miscellaneous Chores

* run fmt for Nomad job definitions. ([bfa3ace](https://github.com/hwakabh/echo-server/commit/bfa3acef6ffd78a2bdf4304047a4ebab6d1eb0ce))


### Continuous Integration

* added configs of semantic-pr. ([cc77664](https://github.com/hwakabh/echo-server/commit/cc77664da095bd5a6ae84792627eb1927ca1a5b5))
* added pipeline for validations of Nomad job definitions. ([de4a289](https://github.com/hwakabh/echo-server/commit/de4a289866f12722d2d97bc7152a8e2a66ad3af4))
* fixed error with fetching NOMAD_VAR_GHCR_TOKEN. ([5aede02](https://github.com/hwakabh/echo-server/commit/5aede027cce9eb3955bb0f4c8e9b6e80dbd349ec))

## [0.2.0](https://github.com/hwakabh/echo-server/compare/v0.1.5...v0.2.0) (2025-03-04)


### Features

* addd type checks for argv[1]. ([74104e7](https://github.com/hwakabh/echo-server/commit/74104e734a3c05e0c07dc9accfa2a21333d9bec7))
* **build:** added build scripts as Makefile. ([7a284ae](https://github.com/hwakabh/echo-server/commit/7a284aec03f481397dcda54dcfc50240d827c8e9))
* enabled to cast port number with socket. ([e4650a7](https://github.com/hwakabh/echo-server/commit/e4650a7aeee1d1f58403f54592206e8e89c28ee0))


### Miscellaneous Chores

* added gcc precheck and updated docs. ([afb9272](https://github.com/hwakabh/echo-server/commit/afb92728ecc2bd3dc0358345ac6943f276cce7fe))
* added notes related to base distroless images. ([b31145c](https://github.com/hwakabh/echo-server/commit/b31145cdd95ad9a2e3cb87b91de6d203d2684f28))
* added PoC code with using envars. ([32a467b](https://github.com/hwakabh/echo-server/commit/32a467b82d79feff1faa179b52526a6d22b2e427))

## [0.1.5](https://github.com/hwakabh/echo-server/compare/v0.1.4...v0.1.5) (2025-03-03)


### Miscellaneous Chores

* **deps:** update hwakabh/semantic-issue-action action to v0.5.1 ([43bae04](https://github.com/hwakabh/echo-server/commit/43bae04daddddcf1cbfb9aca920f5bee631e9e6e))

## [0.1.4](https://github.com/hwakabh/echo-server/compare/v0.1.3...v0.1.4) (2025-02-27)


### Miscellaneous Chores

* **deps:** update all non-major dependencies ([2aa0e7a](https://github.com/hwakabh/echo-server/commit/2aa0e7aaa71ee993649278cba984425c0853f805))
* **deps:** update docker/build-push-action action to v6.14.0 ([e8d83be](https://github.com/hwakabh/echo-server/commit/e8d83be335c49bc9ee2dfe205113078d23937d20))

## [0.1.3](https://github.com/hwakabh/echo-server/compare/v0.1.2...v0.1.3) (2025-02-14)


### Continuous Integration

* added exceptions for cleaning up images and made keeping latest tag. ([ef7e47c](https://github.com/hwakabh/echo-server/commit/ef7e47c8d445daa45abf2e5c0679673f47c390ab))
* fixed CSV formats. ([51aa30a](https://github.com/hwakabh/echo-server/commit/51aa30ad59ccc2e032a0f98de095b72691a51090))
* fixed repository name and keeping tags. ([cb282cb](https://github.com/hwakabh/echo-server/commit/cb282cb38a2a63c26116497c9a5a33681fd38d63))

## [0.1.2](https://github.com/hwakabh/echo-server/compare/v0.1.1...v0.1.2) (2025-02-14)


### Miscellaneous Chores

* **deps:** update gcc docker tag to v14 ([cf85cd2](https://github.com/hwakabh/echo-server/commit/cf85cd22db2ab7f568dc4bf41c30217279d7fddd))

## [0.1.1](https://github.com/hwakabh/echo-server/compare/v0.1.0...v0.1.1) (2025-02-13)


### Bug Fixes

* **ci:** added permissions to push image. ([a8b7160](https://github.com/hwakabh/echo-server/commit/a8b71608ae0e61dc8eded299273cc250e234f1b7))
* **ci:** added permissions to push image. ([d204c37](https://github.com/hwakabh/echo-server/commit/d204c376ab0fe14cbd264b04553328e9ad656cc1))
* **ci:** configuration file path. ([0c19858](https://github.com/hwakabh/echo-server/commit/0c19858db8826f70bc0972ffc1b11bfd14074e7f))
* renamed workflow directories. ([240a361](https://github.com/hwakabh/echo-server/commit/240a3617b9766af5dd713ec0239f1e46d8f09074))


### Documentation

* added commands for run and builds. ([4a28d13](https://github.com/hwakabh/echo-server/commit/4a28d13152e475e1a8708812801597081912efa0))
* added LICENSE. ([97e3a14](https://github.com/hwakabh/echo-server/commit/97e3a144c1a9b21e60455827a23fe88fdb74189b))
* drafted README outlines and fixed title. ([25ff4e9](https://github.com/hwakabh/echo-server/commit/25ff4e955d5b570c22318059430c533b167acc39))


### Miscellaneous Chores

* added declarative config of default label. ([f3df975](https://github.com/hwakabh/echo-server/commit/f3df975748acb8f19fc7b022cb3c8b92228f37f6))
* **build:** added initial Dockerfile. ([18aadcc](https://github.com/hwakabh/echo-server/commit/18aadcc8e3355561d57c86c7c34c9a279c47c8e4))
* **build:** uploaded current Dockerfile. ([18759ed](https://github.com/hwakabh/echo-server/commit/18759eda8089cb30443e684bf61a8bb92f5ef4cb))
* **ci:** added release-please-action. ([130792e](https://github.com/hwakabh/echo-server/commit/130792eb9e15d0bb2bd03c51d00410d938241b79))
* **ci:** finalized triggers and displays. ([63ac032](https://github.com/hwakabh/echo-server/commit/63ac03293318fdd4ec70bfc76425d3b1e6b54c17))
* **deps:** update hwakabh/semantic-issue-action action to v0.5.0 ([8ec51f8](https://github.com/hwakabh/echo-server/commit/8ec51f8b9bdfe4867af7123b6b7a5ed993563612))
* reactivated git controls with commented out. ([08ad496](https://github.com/hwakabh/echo-server/commit/08ad496051f380b0cab94ae53d870bf146bed59d))
* renamed core file. ([53d4c4a](https://github.com/hwakabh/echo-server/commit/53d4c4a8a9e61b0b5771c8cc859fa0ef636876b3))


### Continuous Integration

* added build pipeline workflows. ([13432ca](https://github.com/hwakabh/echo-server/commit/13432ca94b6e987c1307f5557b751e1f93a5dd44))
* added permission to read-contents. ([a103b03](https://github.com/hwakabh/echo-server/commit/a103b03a101a13f41583ba776bb2e4e85bbc2b2d))
* added renovate configs. ([7be1cf8](https://github.com/hwakabh/echo-server/commit/7be1cf87d768ab37d3b73f5d5176e5ccd5aade39))
* added workflows and configs for issue/pr labelers. ([11bce81](https://github.com/hwakabh/echo-server/commit/11bce818ad0119394b548bd53d4487ac55258d6a))
* **build:** added login steps to push images. ([97670e7](https://github.com/hwakabh/echo-server/commit/97670e73d215194ef360ba9bfeb61c9a9eb5e6f8))
* fixed permissions. ([3826ff0](https://github.com/hwakabh/echo-server/commit/3826ff019831502fcda5fa70d2932195c1f6367b))
