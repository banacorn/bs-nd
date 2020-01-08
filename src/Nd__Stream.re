type readable;
type writable;
type duplex;

module Writable = {
  type t = writable;

  [@bs.send.pipe: t]
  external on:
    (
    [@bs.string]
    [
      | `close(unit => unit)
      | `drain(unit => unit)
      | `error(Js.Exn.t => unit)
      | `finish(unit => unit)
      | `pipe(readable => unit)
      | `unpipe(readable => unit)
    ]
    ) =>
    t =
    "on";
  [@bs.send.pipe: t]
  external once:
    (
    [@bs.string]
    [
      | `close(unit => unit)
      | `drain(unit => unit)
      | `error(Js.Exn.t => unit)
      | `finish(unit => unit)
      | `pipe(readable => unit)
      | `unpipe(readable => unit)
    ]
    ) =>
    t =
    "once";

  [@bs.send.pipe: t] external cork: unit = "cork";
  [@bs.send.pipe: t] external destroy: unit = "destroy";
  [@bs.send.pipe: t] external destroy_: Js.Exn.t => t = "destroy";
  [@bs.send.pipe: t] external end_: t = "end";
  [@bs.send.pipe: t]
  external end__: (Node.Buffer.t, string, unit => unit) => t = "end";
  [@bs.send.pipe: t]
  external setDefaultEncoding: string => t = "setDefaultEncoding";
  [@bs.send.pipe: t] external uncork: unit = "uncork";
  [@bs.send.pipe: t] external writable: bool = "writable";
  [@bs.send.pipe: t]
  external writableHighWaterMark: int = "writableHighWaterMark";
  [@bs.send.pipe: t] external writableLength: int = "writableLength";
  [@bs.send.pipe: t] external write: Node.Buffer.t => bool = "write";
  [@bs.send.pipe: t]
  external write_: (Node.Buffer.t, string, unit => unit) => bool = "write";
};

module Readable = {
  type t = readable;
  [@bs.send.pipe: t]
  external on:
    (
    [@bs.string]
    [
      | `close(unit => unit)
      | `data(Node.Buffer.t => unit)
      | [@bs.as "end"] `end_(unit => unit)
      | `error(Js.Exn.t => unit)
      | `pause(unit => unit)
      | `readable(unit => unit)
      | `resume(unit => unit)
    ]
    ) =>
    t =
    "on";
  [@bs.send.pipe: t]
  external once:
    (
    [@bs.string]
    [
      | `close(unit => unit)
        // | `pause(unit => unit)
      | `data(Node.Buffer.t => unit)
      | [@bs.as "end"] `end_(unit => unit)
      | `error(Js.Exn.t => unit)
      | `readable(unit => unit)
      | `resume(unit => unit)
    ]
    ) =>
    t =
    "once";

  [@bs.send.pipe: t] external destroy: t = "destroy";
  [@bs.send.pipe: t] external destroy_: Js.Exn.t => t = "destroy";
  [@bs.send.pipe: t] external isPaused: bool = "isPaused";
  [@bs.send.pipe: t] external pause: t = "pause";
  [@bs.send.pipe: t] external pipe: writable => writable = "pipe";
  [@bs.send.pipe: t]
  external pipe_: (writable, {. "end": bool}) => writable = "pipe";
  [@bs.send.pipe: t] [@bs.send.pipe: t] external read: Node.Buffer.t = "read";
  [@bs.send.pipe: t] external read_: int => Node.Buffer.t = "read";
  [@bs.send.pipe: t] external readable: bool = "readable";
  [@bs.send.pipe: t] external readableFlowing: bool = "readableFlowing";
  [@bs.send.pipe: t]
  external readableHighWaterMark: int = "readableHighWaterMark";
  [@bs.send.pipe: t] external readableLength: int = "readableLength";
  [@bs.send.pipe: t] external resume: t = "resume";
  [@bs.send.pipe: t] external setEncoding: string => t = "setEncoding";
  [@bs.send.pipe: t] external unpipe: writable => t = "unpipe";
  [@bs.send.pipe: t] external unshift: Node.Buffer.t => unit = "unshift";
  [@bs.send.pipe: t] external wrap: 'a => t = "wrap";
};

// NOTE: there's no module magic, just copy and paste
module Duplex = {
  type t = writable;

  [@bs.send.pipe: t]
  external on:
    (
    [@bs.string]
    [
      | `close(unit => unit)
      | `drain(unit => unit)
      | `error(Js.Exn.t => unit)
      | `finish(unit => unit)
      | `pipe(readable => unit)
      | `unpipe(readable => unit)
      | `data(Node.Buffer.t => unit)
      | [@bs.as "end"] `end_(unit => unit)
      | `readable(unit => unit)
      | `resume(unit => unit)
    ]
    ) =>
    t =
    "on";
  [@bs.send.pipe: t]
  external once:
    (
    [@bs.string]
    [
      | `close(unit => unit)
      | `drain(unit => unit)
      | `error(Js.Exn.t => unit)
      | `finish(unit => unit)
      | `pipe(readable => unit)
      | `unpipe(readable => unit)
      | `data(Node.Buffer.t => unit)
      | [@bs.as "end"] `end_(unit => unit)
      | `readable(unit => unit)
      | `resume(unit => unit)
    ]
    ) =>
    t =
    "once";

  // writable part
  [@bs.send.pipe: t] external cork: unit = "cork";
  [@bs.send.pipe: t] external destroy: unit = "destroy";
  [@bs.send.pipe: t] external destroy_: Js.Exn.t => t = "destroy";
  [@bs.send.pipe: t] external end_: t = "end";
  [@bs.send.pipe: t]
  external end__: (Node.Buffer.t, string, unit => unit) => t = "end";
  [@bs.send.pipe: t]
  external setDefaultEncoding: string => t = "setDefaultEncoding";
  [@bs.send.pipe: t] external uncork: unit = "uncork";
  [@bs.send.pipe: t] external writable: bool = "writable";
  [@bs.send.pipe: t]
  external writableHighWaterMark: int = "writableHighWaterMark";
  [@bs.send.pipe: t] external writableLength: int = "writableLength";
  [@bs.send.pipe: t] external write: Node.Buffer.t => bool = "write";
  [@bs.send.pipe: t]
  external write_: (Node.Buffer.t, string, unit => unit) => bool = "write";

  // readable part
  [@bs.send.pipe: t] external isPaused: bool = "isPaused";
  [@bs.send.pipe: t] external pause: t = "pause";
  [@bs.send.pipe: t] external pipe: writable => writable = "pipe";
  [@bs.send.pipe: t]
  external pipe_: (writable, {. "end": bool}) => writable = "pipe";
  [@bs.send.pipe: t] [@bs.send.pipe: t] external read: Node.Buffer.t = "read";
  [@bs.send.pipe: t] external read_: int => Node.Buffer.t = "read";
  [@bs.send.pipe: t] external readable: bool = "readable";
  [@bs.send.pipe: t] external readableFlowing: bool = "readableFlowing";
  [@bs.send.pipe: t]
  external readableHighWaterMark: int = "readableHighWaterMark";
  [@bs.send.pipe: t] external readableLength: int = "readableLength";
  [@bs.send.pipe: t] external resume: t = "resume";
  [@bs.send.pipe: t] external setEncoding: string => t = "setEncoding";
  [@bs.send.pipe: t] external unpipe: writable => t = "unpipe";
  [@bs.send.pipe: t] external unshift: Node.Buffer.t => unit = "unshift";
  [@bs.send.pipe: t] external wrap: 'a => t = "wrap";
};
