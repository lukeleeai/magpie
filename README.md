# GI Agent (Genetic Improvement with AI Agent)

GI Agent: Enhancing software performance through AI-guided genetic improvement!

## Introduction

GI Agent is a tool for automated software improvement using AI agents to guide the genetic improvement process. 
It extends [MAGPIE](#original-project-credits) with AI-powered capabilities to more efficiently traverse the search space of software variants to find improved solutions.

GI Agent supports improvement of both functional (automated bug fixing) and non-functional (e.g., execution time) properties of software.
Like its predecessor, it provides language-agnostic source code representations and enables parameter tuning and algorithm configuration.

## Requirements

- Unix (Linux/macOS/etc; untested on Windows)
- Python 3.11+

## Try it now!

```bash
git clone https://github.com/your-username/gi-agent.git
cd gi-agent
bash run_exp.sh
```

## Documentation

For detailed documentation on the underlying GI framework, please see the original Magpie documentation.

**Tutorials**

- [Quick start](./docs/tutorials/quick_start.md)
- [Search for improved variants](./docs/tutorials/search.md)

**How-to guides**

- [Write a custom fitness function](./docs/howto/custom_fitness_function.md)

**Reference guides**

- [Entry points](./docs/reference/entry_points.md)
- [Fitness functions](./docs/reference/fitness_functions.md)
- [Scenario files](./docs/reference/scenario_file.md)
- [Algorithm configuration model](./docs/reference/paramconfig_model.md)

## Original Project Credits

This project is forked from [Magpie (Machine Automated General Performance Improvement via Evolution of software)](https://github.com/bloa/magpie), developed by Aymeric Blot and Justyna Petke. Magpie itself is based on [PyGGI 2.0](https://github.com/coinse/pyggi), developed at [COINSE KAIST](https://coinse.kaist.ac.kr/) in collaboration with [UCL SOLAR](https://solar.cs.ucl.ac.uk/).  

Part of the original development was supported by UK EPSRC Fellowship EP/P023991/1.

If you use GI Agent for a publication, we kindly ask you to cite both our work and the original MAGPIE paper:

```
@article{blot:2022:corr_1,
  author    = {Aymeric Blot and
               Justyna Petke},
  title     = {{MAGPIE:} {M}achine Automated General Performance Improvement via Evolution of Software},
  journal   = {Computing Research Repository},
  volume    = {abs/2208.02811},
  url       = {https://arxiv.org/abs/2208.02811},
  year      = {2022},
}
```

