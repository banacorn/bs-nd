# bs-node

Node bindings for BuckleScript

# Installation

```
npm install --save @banacorn/bs-node
```

Then add `@banacorn/bs-node` to `bs-dependencies` in your `bsconfig.json`:

```
{
  ...
  "bs-dependencies": ["@@banacorn/bs-node"]
}
```

# Usage

The top level module is named `Nd`, since the name `Node` has been taken.
