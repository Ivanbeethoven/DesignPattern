```rust

/// A trait representing a node in the state graph.
pub trait State<S: ResourceState> {
    /// Provider supplies method to be executed when in this state.
    async fn next(
        self: Box<Self>,
        data: &mut D,
    ) -> Transition<S>;

    /// Provider supplies JSON status patch to apply when entering this state.
    async fn status(&self, state: &mut S) -> Result<S::Status>;
}

struct Roam// 漫游
impl State<MooseState> for Roam {
    fn next(
        self: Box<Self>,
        data: &mut D,
    ) -> Transition<MooseState> {
        loop {
            tokio::time::sleep(2);
            state.food -= 5.0;
            if state.food <= 10.0 {
                return Transition::next(self, Eat);
            }
        }
    }
}

struct Eat;
#[async_trait::async_trait]
impl State<MooseState> for Eat {
    fn next(
        self: Box<Self>,
        data: &mut D,
    ) -> Transition<MooseState> {
        let moose = manifest.latest();
        state.food = moose.spec.weight / 10.0;
        sleep(state.food / 10.0);
        Transition::next(self, Sleep)
    }
}


loop {
    state = state.next(...).later()
}




```


```golang


type containerState interface {
	transition(containerState) error
	destroy() error
	status() Status
}


func (r *runningState) status() Status {
	return Running
}
func (r *runningState) transition(s containerState) error {
	switch s.(type) {
	case *stoppedState:
		if r.c.runType() == Running {
			return ErrRunning
		}
		r.c.state = s
		return nil
	case *pausedState:
		r.c.state = s
		return nil
	case *runningState:
		return nil
	}
	return newStateTransitionError(r, s)
}
func (r *runningState) destroy() error {
	if r.c.runType() == Running {
		return ErrRunning
	}
	return destroy(r.c)
}

// runningState represents a container that
// is currently running.
type runningState struct {
	c *linuxContainer
}
// stoppedState represents a container 
//is a stopped/destroyed state.
type stoppedState struct {}

// A container that is currently pause.  
//It cannot be destroyed in a paused state 
//and must transition back to running first.
type pausedState struct {}



```