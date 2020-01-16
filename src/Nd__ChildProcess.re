/* Node Child Process API */

module Stream = Nd__Stream;

type t;

module Shell = {
  type t;
  external str: string => t = "%identity";
  external bool: bool => t = "%identity";
}

module KillSignal = {
  type t;
  external str: string => t = "%identity";
  external int: int => t = "%identity";
}

module Stdio = {
  type t;
  external str: string => t = "%identity";
  external array: array(Js.nullable(string)) => t = "%identity";
}


//
// child_process.exec(command[, options][, callback])
//

type execCallback =
  (Js.Nullable.t(Js.Exn.t), Node.Buffer.t, Node.Buffer.t) => unit;

[@bs.deriving abstract]
type execOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  shell: Shell.t,
  [@bs.optional]
  timeout: int,
  [@bs.optional]
  maxBuffer: int,
  [@bs.optional]
  killSignal: KillSignal.t,
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  windowsHide: bool,
};

[@bs.module "child_process"]
external exec: (string, execCallback) => t = "exec";
[@bs.module "child_process"]
external exec_: (string, execOption, execCallback) => t = "exec";
[@bs.module "child_process"]
external exec': (string, execOption, Js.t({.})) => t = "exec";

//
// child_process.execFile(file[, args][, options][, callback])
//

[@bs.deriving abstract]
type execFileOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  timeout: int,
  [@bs.optional]
  maxBuffer: int,
  [@bs.optional]
  killSignal: KillSignal.t,
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  windowsHide: bool,
  [@bs.optional]
  windowsVerbatimArguments: bool,
  [@bs.optional]
  shell: Shell.t,
};

[@bs.module "child_process"]
external execFile: (string, array(string), execCallback) => t = "execFile";
[@bs.module "child_process"]
external execFile_: (string, array(string), execFileOption, execCallback) => t =
  "execFile";

//
// child_process.fork(modulePath[, args][, options])
//

[@bs.deriving abstract]
type forkOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  detatched: bool,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  execPath: string,
  [@bs.optional]
  execArgv: array(string),
  [@bs.optional]
  silent: bool,
  [@bs.optional]
  stdio: Stdio.t,
  [@bs.optional]
  windowsVerbatimArguments: bool,
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
};

[@bs.module "child_process"]
external fork: (string, array(string)) => t = "fork";
[@bs.module "child_process"]
external fork_: (string, array(string), forkOption) => t = "fork";

//
// child_process.spawn(command[, args][, options])
//

[@bs.deriving abstract]
type spawnOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  argv0: string,
  [@bs.optional]
  stdio: Stdio.t,
  [@bs.optional]
  detatched: bool,
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  shell: Shell.t,
  [@bs.optional]
  windowsVerbatimArguments: bool,
  [@bs.optional]
  windowsHide: bool,
};

[@bs.module "child_process"]
external spawn: (string, array(string)) => t = "spawn";
[@bs.module "child_process"]
external spawn_: (string, array(string), spawnOption) => t = "spawn";

//
// child_process.execFileSync(file[, args][, options])
//

[@bs.deriving abstract]
type execFileSyncOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  input: Node.Buffer.t,
  [@bs.optional]
  stdio: Stdio.t,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  timeout: int,
  [@bs.optional]
  killSignal: KillSignal.t,
  [@bs.optional]
  maxBuffer: int,
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  windowsHide: bool,
  [@bs.optional]
  shell: Shell.t,
};

[@bs.module "child_process"]
external execFileSync: (string, array(string)) => Node.Buffer.t =
  "execFileSync";
[@bs.module "child_process"]
external execFileSync_:
  (string, array(string), execFileSyncOption) => Node.Buffer.t =
  "execFileSync";

//
// child_process.execSync(command[, options])
//

[@bs.deriving abstract]
type execSyncOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  input: Node.Buffer.t,
  [@bs.optional]
  stdio: Stdio.t,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  shell: Shell.t,
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  timeout: int,
  [@bs.optional]
  killSignal: KillSignal.t,
  [@bs.optional]
  maxBuffer: int,
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  windowsHide: bool,
};

[@bs.module "child_process"]
external execSync: string => Node.Buffer.t = "execSync";
[@bs.module "child_process"]
external execSync_: (string, execSyncOption) => Node.Buffer.t = "execSync";

//
// child_process.spawnSync(command[, args][, options])
//

[@bs.deriving abstract]
type spawnSyncOption = {
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  input: Node.Buffer.t,
  [@bs.optional]
  argv0: string,
  [@bs.optional]
  stdio: Stdio.t,
  [@bs.optional]
  env: Js.t({.}),
  [@bs.optional]
  uid: int,
  [@bs.optional]
  gid: int,
  [@bs.optional]
  timeout: int,
  [@bs.optional]
  killSignal: KillSignal.t,
  [@bs.optional]
  maxBuffer: int,
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  shell: Shell.t,
  [@bs.optional]
  windowsVerbatimArguments: bool,
  [@bs.optional]
  windowsHide: bool,
};

type spawnSyncResult = {
  .
  "pid": int,
  "output": array(Node.Buffer.t),
  "stdout": Node.Buffer.t,
  "stderr": Node.Buffer.t,
  "status": Js.nullable(int),
  "signal": Js.nullable(string),
  "error": Js.Exn.t,
};

[@bs.module "child_process"]
external spawnSync: (string, array(string)) => spawnSyncResult = "spawnSync";
[@bs.module "child_process"]
external spawnSync_:
  (string, array(string), spawnSyncOption) => spawnSyncResult =
  "spawnSync";

//
// Class: ChildProcess
//

// since ChildProcess.t simply extends Events.t,
// here's a converter, there's no magic
external asEventEmitter: t => Nd__Events.t = "%identity";

// special events on ChildProcess.t
[@bs.send.pipe: t]
external on:
  (
  [@bs.string]
  [
    | `close((int, string) => unit)
    | `disconnect(unit => unit)
    | `error(Js.Exn.t => unit)
    | `exit((int, string) => unit)
    | `message(Js.t({.}) => unit)
  ]
  ) =>
  t =
  "on";

[@bs.send.pipe: t]
external once:
  (
  [@bs.string]
  [
    | `close((int, string) => unit)
    | `disconnect(unit => unit)
    | `error(Js.Exn.t => unit)
    | `exit((int, string) => unit)
    | `message(Js.t({.}) => unit)
  ]
  ) =>
  t =
  "once";

// subprocess.channel
[@bs.get] external channel: t => Js.t({.}) = "channel";

// subprocess.connected
[@bs.get] external connected: t => bool = "connected";

// subprocess.disconnect()
[@bs.send.pipe: t] external disconnect: unit = "disconnect";

// subprocess.kill([signal])
[@bs.send.pipe: t] external kill: bool = "kill";
[@bs.send.pipe: t] external kill_: string => bool = "kill";

// subprocess.killed
[@bs.get] external killed: t => bool = "killed";

// subprocess.pid
[@bs.get] external pid: t => int = "pid";

// subprocess.ref()
[@bs.send.pipe: t] external ref: unit = "ref";

// subprocess.send(message[, sendHandle[, options]][, callback])
[@bs.send.pipe: t] external send: Js.t({.}) => bool = "send";
[@bs.send.pipe: t]
external send_:
  (Js.t({.}), Nd__Net.handle, {. "keepOpen": bool}, unit => unit) => bool =
  "send";

// subprocess.stderr
[@bs.get] external stderr: t => Stream.Readable.t = "stderr";

// subprocess.stdin
[@bs.get] external stdin: t => Stream.Writable.t = "stdin";

// subprocess.stdio
[@bs.get] external stdio: t => array(string) = "stdio";

// subprocess.stdout
[@bs.get] external stdout: t => Stream.Readable.t = "stdout";

// subprocess.unref()
[@bs.send.pipe: t] external unref: unit = "unref";
