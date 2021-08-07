<!-- template https://github.com/othneildrew/Best-README-Template -->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/shanenoi/fuzzering">
    <img src="images/Fuzzy.png" alt="Logo" width="300" height="300">
  </a>

  <h3 align="center">Fuzzering</h3>

  <p align="center">
  Fuzzering PostgreSQL Extension
    <br />
    <a href="https://github.com/shanenoi/fuzzering"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/shanenoi/fuzzering">View Demo</a>
    ·
    <a href="https://github.com/shanenoi/fuzzering/issues">Report Bug</a>
    ·
    <a href="https://github.com/shanenoi/fuzzering/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Build and Install</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

![Product Name Screen Shot][product-screenshot]

  Fuzzering is the light weight PostgreSQL extension
  supports searching fuzzy string using 
  <a target="_blank" href="https://en.wikipedia.org/wiki/Levenshtein_distance" >Levenshtein Distance</a>
  <img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/10554aecc5e56da9be4657acd75b9a67b5e8b394">
  ### Introduction
  Fuzzering applies <b>Levenshtein distance</b> for comparing each content of two sentenses.<br>
  In the first step i made, this extension is suitable for find the probability of occurrence keyword from the whole content which type likes as <code>TEXT</code> or <code>VARCHAR</code> <br>
  It will improve the result of <br>
  <code>"SELECT name FROM users WHERE lower(REPLACE(name, ' ', '')) LIKE '%?%'", 'shane'</code>

<!-- GETTING STARTED -->
## Getting Started

<!--This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.-->

### Prerequisites

> You need to install some package for build the extension:
* Clang
  ```sh
  # Ubuntu
  sudo apt install clang

  # Arch
  sudo pacman -S clang
  ```
* LLVM
  ```sh
  # Ubuntu
  sudo apt install llvm

  # Arch
  sudo pacman -S llvm
  ```

### Build and Install

1. Build

```sh
sudo make USE_PGXS=1 install
```

2. Install

```sql
CREATE EXTENSION fuzzering;
```
3. For Rails Developers

- Create migration file
  ```sh
  rails g migration add_fuzzering_extension
  ```
- Add change function
  ```ruby
  class AddFuzzeringExtension < ActiveRecord::Migration[6.1]
    def change
      enable_extension "fuzzering"
    end
  end
  ```
- Migrate
  ```sh
  rake db:migrate
  ```

<!-- USAGE EXAMPLES -->
## Usage

1. SQL query

![Product Name Screen Shot][product-screenshot]
```sql
SELECT name, fuzzering('khăng giấy', name) rank FROM products WHERE fuzzering('khăng giấy', name) > 0.5 ORDER BY rank DESC ;
```
![RESULT QUERY][result-query]

<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/othneildrew/Best-README-Template/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

**_Code Base_**

![CODE BASE][codebase]

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Shanenoi - [@shanenoi](https://twitter.com/shanenoi) - shanenoi.org@gmail.com

Project Link: [Fuzzering](https://github.com/shanenoi/fuzzering)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/shanenoi/fuzzering.svg?style=for-the-badge
[contributors-url]: https://github.com/shanenoi/fuzzering/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/shanenoi/fuzzering.svg?style=for-the-badge
[forks-url]: https://github.com/shanenoi/fuzzering/network/members
[stars-shield]: https://img.shields.io/github/stars/shanenoi/fuzzering.svg?style=for-the-badge
[stars-url]: https://github.com/shanenoi/fuzzering/stargazers
[issues-shield]: https://img.shields.io/github/issues/shanenoi/fuzzering.svg?style=for-the-badge
[issues-url]: https://github.com/shanenoi/fuzzering/issues
[license-shield]: https://img.shields.io/github/license/shanenoi/fuzzering.svg?style=for-the-badge
[license-url]: https://github.com/shanenoi/fuzzering/blob/master/LICENSE.txt
[product-screenshot]: images/show_product.png
[result-query]: images/result.png
[codebase]: images/codebase.svg
